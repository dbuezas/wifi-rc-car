export default class KeyboardControl {
  onMove = (x: number, y: number) => {};
  current = { x: 0, y: 0 };
  target = { x: 0, y: 0 };
  smoothing = { x: 0.2, y: 0.2 };
  s_x = 0.2;
  s_y = 0.2;
  interval?: ReturnType<typeof setInterval>;
  constructor() {
    document.body.addEventListener("keydown", this.onkeydown);
    document.body.addEventListener("keyup", this.onkeyup);
  }

  update = () => {
    this.current.x =
      this.target.x * this.smoothing.x +
      this.current.x * (1 - this.smoothing.x);
    this.current.y =
      this.target.y * this.smoothing.y +
      this.current.y * (1 - this.smoothing.y);
    this.onMove(this.current.x, this.current.y);
    if (Math.abs(this.current.x) < 0.001 && Math.abs(this.current.y) < 0.001) {
      clearInterval(this.interval);
      this.interval = undefined;
    }
  };
  onkeydown = (event: KeyboardEvent) => {
    let ignore = false;
    if (event.key == "ArrowUp") {
      this.target.y = event.shiftKey ? -0.5 : -1;
    } else if (event.key == "ArrowDown") {
      this.target.y = event.shiftKey ? 0.5 : 1;
    } else if (event.key == "ArrowLeft") {
      this.target.x = -1;
    } else if (event.key == "ArrowRight") {
      this.target.x = 1;
    } else {
      ignore = true;
    }
    if (!ignore) {
      event.preventDefault();
      if (!this.interval) this.interval = setInterval(this.update, 50);
    }
  };
  onkeyup = (event: KeyboardEvent) => {
    let ignore = false;
    if (event.key == "ArrowUp") {
      this.target.y = 0;
    } else if (event.key == "ArrowDown") {
      this.target.y = 0;
    } else if (event.key == "ArrowLeft") {
      this.target.x = 0;
    } else if (event.key == "ArrowRight") {
      this.target.x = 0;
    } else {
      ignore = true;
    }
    if (!ignore) {
      event.preventDefault();
    }
  };
}
