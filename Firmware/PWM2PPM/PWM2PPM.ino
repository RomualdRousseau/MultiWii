#include "config.h"
#include "hal.h"

void conversion_PWM_to_PPM(float dt)
{
  for (int i = 0; i < HAL_RECEIVER_MAX_CHANNELS; i++)
  {
    int v = HAL.pwms[i].read();
    if(v < 800 || v > 2400) {
      HAL.ppm.analogWrite(i, 512);
    } else {
      HAL.ppm.analogWrite(i, map(v, 800, 2400, 0, 1023));
    }
  }
}

void setup() {
  HAL.init();

  Task tasks[] = {
    {conversion_PWM_to_PPM, TASK_400HZ, 0}
  };
  HAL.scheduler.calibrate(&tasks[0], 100);
  HAL.scheduler.register_tasks(tasks, 1);
}

void loop() {
  HAL.scheduler.run_mainloop();
}
