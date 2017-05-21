#ifndef _NVM_HEAD
#define _NVM_HEAD

///执行指令类型
typedef int ExecCommand;

#define CMD_POS 0
#define CMD_LEN 6
#define A_POS CMD_LEN
#define A_LEN 8
#define B_POS (CMD_LEN + A_LEN)
#define B_LEN 8

enum Operator
{
	O_NONE = 0, O_LOAD, O_MOVE, O_ADD, O_SUB, O_MUL, O_DIV, O_MOD, 
	O_CALL, O_RETURN
};

#define mask_1(pos, len)  (~(((~0)<<len))<<pos)
#define mask_0(pos, len) ~(mask_1(pos, len))
#define setMask(cmd, o, pos, len) cmd = (mask_0(pos, len)&cmd) | (mask_1(pos, len)&(o<<pos))
#define getMask(cmd, pos, len) (mask_1(pos, len)&cmd)>>pos

#endif
