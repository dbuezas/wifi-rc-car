import { assertExhaustive, constrain, debounce, sleep } from "./utils";
type State = {
  x: number;
  y: number;
  lag: number;
  battery: number;
  ram: number;
  irresponsive: boolean;
};
export default class RemoteControl {
  left = {
    el: document.querySelector<HTMLElement>("#joy-left")!,
    dot: document.querySelector<HTMLElement>("#joy-left .dot")!,
    rect: new DOMRect(),
  };
  right = {
    el: document.querySelector<HTMLElement>("#joy-right")!,
    dot: document.querySelector<HTMLElement>("#joy-right .dot")!,
    rect: new DOMRect(),
  };
  unified = {
    el: document.querySelector<HTMLElement>("#joy-unified")!,
    dot: document.querySelector<HTMLElement>("#joy-unified .dot")!,
    rect: new DOMRect(),
  };
  containerEl = document.querySelector<HTMLElement>("#container")!;
  statusEl = document.querySelector<HTMLElement>("#status")!;
  statsEl = document.querySelector<HTMLElement>("#stats")!;
  joyModeEl = document.querySelector<HTMLSelectElement>("#joystick-mode")!;
  state = new Proxy<State>(
    {
      x: 0,
      y: 0,
      lag: 0,
      battery: 0,
      ram: 0,
      irresponsive: false,
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
  msg_i = 0;
  msg_ms: number[] = [];
  last_msg = new Int8Array(0);
  socket?: WebSocket;
  lastMsgTime = 0;
  irresponsive = false;

  onMove = (x: number, y: number) => {};

  constructor() {
    this.containerEl.addEventListener("touchstart", this.ontouch);
    this.containerEl.addEventListener("touchmove", this.ontouch);
    this.containerEl.addEventListener("touchend", this.ontouch);
    this.containerEl.addEventListener("mousedown", this.ontouch);
    this.containerEl.addEventListener("mousemove", this.ontouch);
    window.addEventListener("mouseup", this.ontouch);
  }
  init() {
    this.connect();
    this.relayout();
    this.joyModeEl.addEventListener("change", this.relayout);
    setInterval(() => {
      this.state.irresponsive = Date.now() - this.lastMsgTime > 5000;
    }, 1000);

    window.addEventListener("resize", async () => {
      await sleep(100);
      this.relayout();
    });
  }

  connect() {
    try {
      this.socket?.close();
    } catch (e) {}
    this.socket = new WebSocket("ws://8.8.4.4/ws");
    this.socket.addEventListener("open", this.render);
    this.socket.addEventListener("error", this.render);
    this.socket.addEventListener("close", this.render);
    this.socket.onmessage = async (event) => {
      const buffer = await event.data.arrayBuffer();
      const dv = new DataView(buffer);
      const type = dv.getUint8(0);
      if (type === 0) {
        this.state.x = dv.getInt8(1) / 100;
        this.state.y = dv.getInt8(2) / 100;
        const i = dv.getUint8(3);
        this.state.lag = Date.now() - this.msg_ms[i];
        this.msg_ms[i] = Number.NaN;
        this.onMove(this.state.x, this.state.y);
      } else if (type === 1) {
        this.state.battery = dv.getUint16(1, true) / 1000;
        this.state.ram = dv.getUint8(3);
      }
      this.lastMsgTime = Date.now();
    };
    this.render();
  }
  relayout = () => {
    this.right.rect = this.right.el.getBoundingClientRect();
    this.unified.rect = this.unified.el.getBoundingClientRect();
    this.left.rect = this.left.el.getBoundingClientRect();
    switch (this.joyModeEl.value) {
      case "unified":
        this.left.el.style.visibility = "hidden";
        this.right.el.style.visibility = "hidden";
        this.unified.el.style.visibility = "";

        break;
      case "throttle-wheel":
      case "wheel-throttle":
      case "throttle-throttle":
        this.left.el.style.visibility = "";
        this.right.el.style.visibility = "";
        this.unified.el.style.visibility = "hidden";
        break;
    }
    const throttle_left = this.joyModeEl.value.startsWith("throttle");
    const wheel_left = this.joyModeEl.value.startsWith("wheel");
    const throttle_right = this.joyModeEl.value.endsWith("throttle");
    const wheel_right = this.joyModeEl.value.endsWith("wheel");
    this.left.el.querySelector<HTMLElement>(".x-bar")!.style.visibility =
      wheel_left ? "" : "hidden";
    this.left.el.querySelector<HTMLElement>(".y-bar")!.style.visibility =
      throttle_left ? "" : "hidden";
    this.right.el.querySelector<HTMLElement>(".x-bar")!.style.visibility =
      wheel_right ? "" : "hidden";
    this.right.el.querySelector<HTMLElement>(".y-bar")!.style.visibility =
      throttle_right ? "" : "hidden";
    this.render();
  };
  renderDot(
    { dot, rect }: { dot: HTMLElement; rect: DOMRect },
    ctrl: "wheel" | "throttle" | "left-throttle" | "right-throttle" | "unified"
  ) {
    let x = 0;
    let y = 0;
    if (ctrl === "wheel") {
      x = this.state.x;
    } else if (ctrl === "throttle") {
      y = this.state.y;
    } else if (ctrl === "left-throttle") {
      y = this.state.y + (this.state.x / 2) * (this.state.y > 0 ? 1 : -1);
    } else if (ctrl === "right-throttle") {
      y = this.state.y + (this.state.x / 2) * (this.state.y > 0 ? -1 : 1);
    } else if (ctrl === "unified") {
      x = this.state.x;
      y = this.state.y;
    } else {
      assertExhaustive(ctrl);
    }
    dot.style.transform = `translate(${((x + 1) / 2) * rect.width}px, ${
      ((y + 1) / 2) * rect.height
    }px)`;
  }
  render = debounce(() => {
    switch (this.joyModeEl.value) {
      case "unified":
        this.renderDot(this.unified, "unified");
        break;
      case "throttle-wheel":
        this.renderDot(this.left, "throttle");
        this.renderDot(this.right, "wheel");
        break;
      case "wheel-throttle":
        this.renderDot(this.right, "throttle");
        this.renderDot(this.left, "wheel");
        break;
      case "throttle-throttle":
        this.renderDot(this.left, "left-throttle");
        this.renderDot(this.right, "right-throttle");
        break;
    }
    this.statsEl.textContent = `${this.state.battery.toFixed(2)}v x 4|${
      this.state.ram
    }kb|${this.state.lag}ms`;
    const readyState = (
      {
        [WebSocket.CONNECTING]: "CONNECTING",
        [WebSocket.OPEN]: "CONNECTED",
        [WebSocket.CLOSING]: "CLOSING",
        [WebSocket.CLOSED]: "CLOSED",
        "?": "?",
      } as const
    )[this.socket?.readyState || "?"];
    if (readyState == "CONNECTED" && this.state.irresponsive) {
      this.statusEl.textContent = "RELOAD";
      this.statusEl.style.color = "red";
    } else {
      this.statusEl.textContent = readyState;
      this.statusEl.style.color = {
        CONNECTED: "green",
        CONNECTING: "yellow",
        CLOSING: "red",
        CLOSED: "red",
        "?": "red",
      }[readyState];
    }
  });
  move = async (x: number, y: number) => {
    // if (Math.abs(y) > 1 || Math.abs(x) > 1) {
    //   window.navigator.vibrate?.(250);
    //   console.log("vibrate");
    // } else {
    //   window.navigator.vibrate?.(0);
    // }
    x = constrain(x, -1, 1);
    y = constrain(y, -1, 1);
    const msg = Int8Array.from([x * 100, y * 100]);
    const noChange = JSON.stringify(msg) === JSON.stringify(this.last_msg);
    if (noChange) return;
    this.last_msg = msg;

    this.msg_i = (this.msg_i + 1) % 256;
    this.msg_ms[this.msg_i] = Date.now();
    try {
      this.socket!.send(Int8Array.from([...msg, this.msg_i]));
    } catch (e) {
      console.error(e);
      // this.connect();
      // this.state.x = x;
      // this.state.y = y;
      // this.onMove(x, y);
    }
  };
  ontouch = (event: TouchEvent | MouseEvent) => {
    if (event instanceof MouseEvent) {
      if (event.type === "mouseup") return this.move(0, 0);
      if (event.buttons == 0) return;
    }
    event.preventDefault();
    event.stopPropagation();
    const rects = [this.left.rect, this.right.rect, this.unified.rect];
    const touches =
      event instanceof TouchEvent ? Array.from(event.touches) : [event];
    let padUnified = { x: 0, y: 0 };
    let padLeft = { x: 0, y: 0 };
    let padRight = { x: 0, y: 0 };
    for (let i in touches) {
      const { clientX, clientY, target } = touches[i];
      if (target === this.unified.el) {
        padUnified.x = ((clientX - rects[2].left) / rects[2].width) * 2 - 1;
        padUnified.y = ((clientY - rects[2].top) / rects[2].height) * 2 - 1;
      } else if (target === this.left.el) {
        padLeft.x = ((clientX - rects[0].left) / rects[0].width) * 2 - 1;
        padLeft.y = ((clientY - rects[0].top) / rects[0].height) * 2 - 1;
      } else if (target === this.right.el) {
        padRight.x = ((clientX - rects[1].left) / rects[1].width) * 2 - 1;
        padRight.y = ((clientY - rects[1].top) / rects[1].height) * 2 - 1;
      }
    }
    let x = 0;
    let y = 0;
    switch (this.joyModeEl.value) {
      case "unified":
        x = padUnified.x;
        y = padUnified.y;
        break;
      case "wheel-throttle":
        x = padLeft.x;
        y = padRight.y;
        break;
      case "throttle-wheel":
        x = padRight.x;
        y = padLeft.y;
        break;
      case "throttle-throttle":
        y = (padRight.y + padLeft.y) / 2;
        x = (padLeft.y - padRight.y) * (y > 0 ? 1 : -1);
        break;
    }
    this.move(x, y);
  };
}
