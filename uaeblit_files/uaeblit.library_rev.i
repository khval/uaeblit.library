VERSION		EQU	53
REVISION	EQU	1

DATE	MACRO
		dc.b '18.11.2023'
		ENDM

VERS	MACRO
		dc.b 'uaeblit.library 53.1'
		ENDM

VSTRING	MACRO
		dc.b 'uaeblit.library 53.1 (18.11.2023)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: uaeblit.library 53.1 (18.11.2023)',0
		ENDM
