 /*
 * STD_MACROS.h
 *
 * Created: 9/20/2022 11:43:50 PM
 *  Author: amrkh
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8

#define READ_BIT(PORT,BIT) (PORT&(1u<<BIT))>>BIT

#define TOG_BIT(PORT,BIT) PORT=PORT^(1<<BIT)

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)

#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)

#define ROR(reg,num) reg=(reg>>num)|(reg<<(REGISTER_SIZE-num))

#define ROL(reg,num) reg=(reg<<num)|(reg>>(REGISTER_SIZE-num))

#endif /* STD_MACROS_H_ */