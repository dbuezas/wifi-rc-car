export class Deferred {
  resolve = () => {};
  reject = () => {};
  promise: Promise<void>;

  constructor() {
    this.promise = new Promise((resolve, reject) => {
      this.resolve = resolve;
      this.reject = reject;
    });
  }
}

export const sleep = (ms: number) => new Promise((r) => setTimeout(r, ms));
export const constrain = (x: number, min: number, max: number) =>
  (x = x > max ? max : x < min ? min : x);

export function assertExhaustive(value: never): never {
  throw new Error("Reached unexpected case in exhaustive switch");
}

export function debounce<F extends (...args: Parameters<F>) => any>(
  func: F
): (...args: Parameters<F>) => void {
  let timeout: number;
  return (...args: Parameters<F>): void => {
    cancelAnimationFrame(timeout);
    timeout = requestAnimationFrame(() => func(...args));
  };
}
