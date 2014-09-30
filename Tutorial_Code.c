int main (void)
{
  int VAR1 = 0;
  int VAR2 = 0;
  VAR2 = 5;
  VAR1 = 6;
  VAR1 = VAR2 + VAR1;
  while (1);
  return (0);
}


// 				PRESERVE8
// 				THUMB
// Addr_Reg		RN			r7 ; I am only going to use Reg 7 for addresses
// Data_Reg2		RN			r6 ; I am only going to use Register 6 for my addresses
// Data_Reg1		RN			r5 ; I am only going to use Register 5 for data going to or coming from memory 						
// INITAL_MSP		EQU			0x20001000	
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				
// 				AREA	RESET,DATA,READONLY
// 				EXPORT __Vectors
// 				
// __Vectors		DCD			INITAL_MSP
// 				DCD			Reset_Handler
// 				ALIGN
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 				AREA	|.data|,DATA,READWRITE		
// VAR_1			DCD			0x00    ;These are each 2 bytes wide.
// VAR_2			DCD			0x00
// 				ALIGN

// 				AREA    |.text|, CODE, READONLY
// 				EXPORT 	Reset_Handler
// 				ENTRY ;Needed to signal the start of a program
// 				
// 				
// Reset_Handler
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN			PROC	
// 				
// 				ldr		Addr_Reg,=VAR_2
// 				mov		r8,#5
// 				str		r8,[Addr_Reg]
// 				
// 				ldr		Addr_Reg,=VAR_1
// 				mov		r8,#6
// 				str		r8,[Addr_Reg]	  	;Stores the value located in R0 in the location 0x40010C04
// 				
// 				ldr		Addr_Reg,=VAR_2
// 				ldr		Data_Reg1,[Addr_Reg]
// 				
// 				ldr		Addr_Reg,=VAR_1
// 				ldr		Data_Reg2,[Addr_Reg]	  	;Stores the value located in R0 in the location 0x40010C04
// 				
// 				ADD		r0,Data_Reg1,Data_Reg2
// 				ldr		Addr_Reg,=VAR_1
// 				str		r0, [Addr_Reg]
// 				ldr		r4, [Addr_Reg]
// 				
// 				
// 				ASSERT 	1 < 2
//                 B      MAIN
//                 
// 				ENDP

// 				ALIGN
// 				END
