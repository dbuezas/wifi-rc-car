import { debounce, Deferred, sleep } from "./utils";
type State = {
  status: "idle" | "playing" | "recording";
  remaining: number;
};
export default class Recorder {
  memory: { t: number; x: number; y: number }[] = [];
  stopper = new Deferred();
  playEl = document.querySelector<HTMLButtonElement>("button#play")!;
  recordEl = document.querySelector<HTMLButtonElement>("#record")!;
  onMove = (x: number, y: number) => {};
  state = new Proxy<State>(
    {
      status: "idle",
      remaining: 0,
    },
    {
      set: <P extends keyof State>(target: State, p: P, newValue: State[P]) => {
        if (target[p] !== newValue) {
          target[p] = newValue;
          this.render();
        }
        return true;
      },
    }
  );
  constructor() {
    this.recordEl.addEventListener("click", this.record);
    this.playEl.addEventListener("click", this.play);
    this.render();
  }
  add(x: number, y: number) {
    if (this.state.status == "recording") {
      const t = Date.now();
      this.memory.push({ t, x, y });
      this.render();
    }
  }
  record = () => {
    if (this.state.status == "recording") return this.recordEnd();
    return this.recordStart();
  };
  recordStart() {
    this.state.status = "recording";
    this.memory = [];
    this.onMove(0, 0);
  }
  recordEnd() {
    this.state.status = "idle";
  }
  play = () => {
    if (this.state.status == "playing") return this.playEnd();
    return this.playStart();
  };
  playEnd() {
    this.state.status = "idle";
    this.stopper.reject();
    this.onMove(0, 0);
  }
  async playStart() {
    this.state.status = "playing";
    this.stopper = new Deferred();

    let t = this.memory[0].t;
    for (let entry of this.memory) {
      this.state.remaining = this.memory.slice(-1)[0].t - t;
      this.render();
      await Promise.race([sleep(entry.t - t), this.stopper.promise]);
      t = entry.t;
      this.onMove(entry.x, entry.y);
      this.state.remaining = this.memory.slice(-1)[0].t - entry.t;
    }
    this.playEnd();
  }
  render = debounce(() => {
    if (this.state.status === "recording") {
      let recordedMs = 0;
      if (this.memory.length)
        recordedMs = this.memory[this.memory.length - 1].t - this.memory[0].t;
      this.playEl.textContent = "PLAY";
      this.recordEl.textContent = "STOP " + (recordedMs / 1000).toFixed(2);
      this.recordEl.disabled = false;
      this.playEl.disabled = true;
    } else if (this.state.status === "playing") {
      this.playEl.textContent =
        "STOP " + (this.state.remaining / 1000).toFixed(2);
      this.recordEl.textContent = "RECORD";
      this.playEl.disabled = false;
      this.recordEl.disabled = true;
    } else if (this.state.status === "idle") {
      this.playEl.textContent = "PLAY";
      this.recordEl.textContent = "RECORD";
      this.recordEl.disabled = false;
      this.playEl.disabled = this.memory.length === 0;
    }
  });
}
