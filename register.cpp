#include "modeladm.h" 
#include "mainsimu.h"

#include "queue.h"      // class Queue
#include "cola_sal.h"     //Class cola_sal
#include "ruteo_ip.h"     //Class ruteo_ip

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
        SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<cola_sal>() , "cola_sal" ) ;
        SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ruteo_ip>() , "ruteo_ip" ) ;

}


