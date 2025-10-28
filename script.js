let hr = 0;
let min = 0;
let sec = 0;
let timerId = null;

const hrEle = document.getElementById("hours");
const minEle = document.getElementById("minutes");
const secEle = document.getElementById("seconds");
const pauseAndResume = document.getElementById("pauseBtn");

function updateDisplay() {
  hrEle.textContent = hr;
  minEle.textContent = min;
  secEle.textContent = sec;
}

function startTimer() {
  if (timerId) return; 

  timerId = setInterval(() => {
    sec++;
    if (sec === 60) {
      sec = 0;
      min++;
      if (min === 60) {
        min = 0;
        hr++;
      }
    }
    updateDisplay();
  }, 1000);
}

function pauseOrResumeTimer() {
  const currentText = pauseAndResume.innerHTML;
  if (currentText === "Pause") {
    clearInterval(timerId);
    timerId = null;
    pauseAndResume.innerHTML = "Resume";
  } else {
    startTimer();
    pauseAndResume.innerHTML = "Pause";
  }
}

function endTimer() {
  clearInterval(timerId);
  timerId = null;
  hr = 0;
  min = 0;
  sec = 0;
  updateDisplay();
  pauseAndResume.innerHTML = "Pause";
}


document.getElementById("startBtn").addEventListener("click", startTimer);
pauseAndResume.addEventListener("click", pauseOrResumeTimer);
document.getElementById("endBtn").addEventListener("click", endTimer);