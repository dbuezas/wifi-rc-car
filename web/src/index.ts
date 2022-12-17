document
  .querySelector<HTMLSelectElement>("#song")!
  .addEventListener("change", (event) => {
    const { value } = event.target as HTMLSelectElement;
    fetch(`http://8.8.4.4/${value}`);
  });
window.scroll(0, 10);
window.onscroll = () => {
  window.scroll(0, 10);
  // so that the captive portal doesnt pull to refresh
};

import KeyboardControl from "./keyboard";
import Recorder from "./recorder";
import RemoteControl from "./remote";

const recorder = new Recorder();
const remoteControl = new RemoteControl();
const keyboardControl = new KeyboardControl();

recorder.onMove = (x, y) => remoteControl.move(x, y);
remoteControl.onMove = (x, y) => recorder.add(x, y);
keyboardControl.onMove = (x, y) => remoteControl.move(x, y);

remoteControl.init();
