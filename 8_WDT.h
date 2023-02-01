#include <WDTZero.h>

WDTZero MyWatchDoggy; // Define WDT  

void myshutdown()
{

saveWDTln(stringRTC());
NVIC_SystemReset();
  
}

void WDTsetup() {

 MyWatchDoggy.attachShutdown(myshutdown);
 MyWatchDoggy.setup(WDT_SOFTCYCLE2M);  // initialize WDT-softcounter refesh cycle on 2 minutes interval
}
