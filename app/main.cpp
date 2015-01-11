#include <cfg/bsp/bsp.h>
#include <drv/led/led.h>

int main()
{
    drv::led ledGreen(bsp::ledGreenPort, bsp::ledGreenPin);
    ledGreen.write();

    drv::led ledRed(bsp::ledRedPort, bsp::ledRedPin);
    ledRed.write();
    while(1);
}
