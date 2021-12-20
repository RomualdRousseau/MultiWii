#include <Scheduler.h>
#include <CT8Z.h>
#include <PWMDevices.h>

class _HAL_t
{
public:
  Scheduler       scheduler;
  PWMDeviceInput  pwms[HAL_RECEIVER_MAX_CHANNELS];
  CT8ZClass       ppm;
  
  void init();
};

static _HAL_t HAL;

void _HAL_t::init()
{
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("PWM to PPM v1.0");

  ppm = CT8Z;
  ppm.begin(true);

  pwms[0].attach(HAL_RECEIVER_PIN1);
  pwms[1].attach(HAL_RECEIVER_PIN2);
  pwms[2].attach(HAL_RECEIVER_PIN3);
  pwms[3].attach(HAL_RECEIVER_PIN4);
  pwms[4].attach(HAL_RECEIVER_PIN5);
  pwms[5].attach(HAL_RECEIVER_PIN6);
  pwms[6].attach(HAL_RECEIVER_PIN7);
  pwms[7].attach(HAL_RECEIVER_PIN8);

  delay(100);
}
