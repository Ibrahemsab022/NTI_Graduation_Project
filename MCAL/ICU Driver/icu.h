#ifndef ICU_H_
#define ICU_H_

/*********************includes*********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************General(inputs)*************************************************/


typedef struct
{
	u32 CR1        ;
	u32 CR2        ;
	u32 SMCR       ;
	u32 DIER       ;
	u32 SR         ;
	u32	EGR        ;
	u32 CCMR1      ;
	u32	CCMR2      ;
	u32 CCER       ;
	u32 CNT        ;
	u32 PSC        ;
	u32 ARR        ;
	u32 RESERVED_1 ;
	u32 CCR1       ;
	u32 CCR2       ;
	u32 CCR3       ;
	u32 CCR4       ;
	u32 RESERVED_2 ;
	u32 DCR        ;
	u32 DMAR       ;
	u32 OR         ;
}TMR_t;


#define TMR2_ADD		((volatile TMR_t *)(0x40000000))
#define TMR3_ADD		((volatile TMR_t *)(0x40000400))
#define TMR4_ADD		((volatile TMR_t *)(0x40000800))
#define TMR5_ADD		((volatile TMR_t *)(0x40000C00))


#define CEN_BIT			    0
#define OPM_BIT			    3
#define CC1S_SHIFT		    0
#define OC1M_SHIFT		    4
#define CC2S_SHIFT		    8
#define OC2M_SHIFT		    12
#define CC3S_SHIFT		    0
#define OC3M_SHIFT		    4
#define CC4S_SHIFT		    8
#define OC4M_SHIFT		    12
#define CC1IE_BIT		    1
#define CC1P_BIT			1
#define CC1NP_BIT			3
#define CC3P_BIT			9
#define CC3NP_BIT			11
#define CC3EN_BIT			8
#define CC1EN_BIT		    0

#define OC1PE_BET


typedef enum
{
	TMR2,
	TMR3,
	TMR4,
	TMR5
}TMRN_t;

typedef enum
{
	CH1 = 1,
	CH2,
	CH3,
	CH4
}CHN_t;

typedef enum
{
	FROZEN,
	ACTIVE,
	INACTIVE,
	TOGGLE,
	INACTIVE_FORCE,
	ACTIVE_FORCE,
	PWM_MODE1,
	PWM_MODE2
}CMPFn_t;

typedef enum
{
	OUTPUT_1,
	IC_T2,
	IC_T1,
	IC_TRC
}CH_MODE_t;

typedef enum
{
	RISIN,
	FALLIN,
	RESERVED,
	BOTH
}EDGE_t;

/*********************************************FUNCTION*************************************************/

void TMR_voidStart(TMRN_t Copy_uddtTMR_no);
void TMR_voidStop(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetPrescaler(TMRN_t Copy_uddtTMR_no, u16 Copy_u16Value);
void TMR_voidEnableOPM(TMRN_t Copy_uddtTMR_no);
void TMR_voidCountRst(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetChannelOutput(TMRN_t Copy_uddtTMR_no, CMPFn_t Copy_uddtFn, CHN_t Copy_uddtChNo);
void TMR_voidSetChannelInput(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtCH_no);
void TMR_voidSetARR(TMRN_t Copy_uddtTMR_no, u32 Copy_u32Value);
void TMR_voidStop(TMRN_t Copy_uddtTMR_no);
void TMR_voidClearCount(TMRN_t Copy_uddtTMR_no);
void TMR_voidEnableICUInt(TMRN_t Copy_uddtTMR_no);
void TMR_voidSetCMPVal(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo, u32 cmpValue);
u32 TMR_voidReadCapture(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo);
void Timer3_voidCapture_Compare_Init(void);




#endif
