/*
 * STD_MACROS.h
 *
 * Created: 9/20/2022 11:43:50 PM
 *  Author: amrkh
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
/*
#define REGISTER_SIZE 8

#define READ_BIT(PORT,BIT) PORT=(PORT&(1<<BIT))>>BIT

#define TOG_BIT(PORT,BIT) PORT=PORT^(1<<BIT)

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)

#define CLR_BIT(PORT,BIT) PORT&=(~(1<<BIT))

#define ROR(reg,num) reg=(reg>>num)|(reg<<(REGISTER_SIZE-num))

#define ROL(reg,num) reg=(reg<<num)|(reg>>(REGISTER_SIZE-num))

*/

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)    (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)        reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))





#endif /* STD_MACROS_H_ */