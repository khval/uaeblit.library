VERSION = 53
REVISION = 1

.macro DATE
.ascii "18.11.2023"
.endm

.macro VERS
.ascii "uaeblit.library 53.1"
.endm

.macro VSTRING
.ascii "uaeblit.library 53.1 (18.11.2023)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: uaeblit.library 53.1 (18.11.2023)"
.byte 0
.endm
