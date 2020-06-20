
#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "GLOBALINT_Register.h"
#include "GLOBALINT_Interface.h"



void GLOBALINT_VidEnable(void);

{
	SET_BIT(SREG,7);
}

void GLOBALINT_VidDisable(void);
{
	CLR_BIT(SREG,7);
}
