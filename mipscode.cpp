ofstream mcode("mipsinter.s");
ofstream f("mips.s");

string def = "";
int tempco = 0;
map<string,int> vars;

void genmips(string label,string op=def,string a1=def,string a2=def,string ret=def)
{
	if(label != "")
	{
		mcode << label << ":" << endl;
	}
	else if(op == "exit")
	{
		mcode << "jr	$ra" << endl;
	}
	else if(op == "goto")
	{
		mcode << "j		" << a1 << endl;
	}
	else if(op == "pushreturn")
	{
		mcode << "addi	$sp,$sp,-4" << endl;
		mcode << "sw	$ra,0($sp)" << endl;
	}
	else if(op == "popreturn")
	{
		mcode << "lw	$ra,0($sp)" << endl;
		mcode << "addi	$sp,$sp,4" << endl;	
	}
	else if(op == "call")
	{
		mcode << "jal	" << a1 << endl;
	}
	else
	{
		if(a1 != def)
		{
			if(a1[0] <= '9' and a1[0] >= '0')
				mcode << "li	$t1, " << a1 << endl;
			else
			{
				a1 = "_"+a1;
				mcode << "lw	$t1, " << a1 << endl;
				if(vars.find(a1) == vars.end())
					vars[a1] = 1;
			}
		}
		if(a2 != def)
		{
			if(a2[0] <= '9' and a2[0] >= '0')
				mcode << "li	$t2, " << a2 << endl;
			else
			{
				a2 = "_"+a2;
				mcode << "lw	$t2, " << a2 << endl;
				if(vars.find(a2) == vars.end())
					vars[a2] = 1;
			}
		}
		if(op == "restorereturn")
		{
			mcode << "sw	$v0, " << a1 << endl;
		}
		if(op == "copy")
		{
			mcode << "lw	$t8, " << a1 << endl;
			mcode << "sw	$t8, " << a2 << endl;
		}
		if(op == "push")
		{
			mcode << "addi	$sp,$sp,-4" << endl;
			mcode << "lw	$t8, " << a1 << endl;
			mcode << "sw	$t8,0($sp)" << endl;
		}
		if(op == "pop")
		{
			mcode << "lw	$t8,0($sp)" << endl;
			mcode << "sw	$t8, " << a1 << endl;
			mcode << "addi	$sp,$sp,4" << endl;
		}
		if(op == "if")
		{
			mcode << "bgtz	$t1, " << ret << endl;
			return;
		}
		if(op == "return")
		{
			mcode << "move	$v0, $t1" << endl;
		}
		if(op == "read")
		{
			mcode << "li	$v0, 5" << endl;
			mcode << "syscall" << endl;
			mcode << "sw	$v0, " << a1 << endl;
		}
		if(op == "write")
		{
			mcode << "li	$v0, 1" << endl;
			mcode << "move	$a0, $t1" << endl;
			mcode << "syscall" << endl;
		}
		if(op == "&&")
		{
			mcode << "and	$t0,$t1,$t2" << endl;
		}
		if(op == "||")
		{
			mcode << "or	$t0,$t1,$t2" << endl;
		}
		if(op == "+")
		{
			mcode << "add	$t0,$t1,$t2" << endl;
		}
		if(op == "-")
		{
			mcode << "sub	$t0,$t1,$t2" << endl;
		}
		if(op == "*")
		{
			mcode << "mult	$t1,$t2" << endl;
			mcode << "mflo	$t0" << endl;
		}
		if(op == "/")
		{
			mcode << "div	$t1,$t2" << endl;
			mcode << "mflo	$t0" << endl;
		}
		if(op == ">=")
		{
			mcode << "slt	$t3,$t1,$t2" << endl;
			mcode << "xori	$t0,$t3,1" << endl;
		}
		if(op == "<=")
		{
			mcode << "slt	$t3,$t2,$t1" << endl;
			mcode << "xori	$t0,$t3,1" << endl;
		}
		if(op == ">")
		{
			mcode << "slt	$t0,$t2,$t1" << endl;
		}
		if(op == "<")
		{
			mcode << "slt	$t0,$t1,$t2" << endl;
		}
		if(op == "==")
		{
			mcode << "slt	$t3,$t1,$t2" << endl;
			mcode << "slt	$t4,$t2,$t1" << endl;
			mcode << "or	$t5,$t3,$t4" << endl;
			mcode << "xori	$t0,$t5,1" << endl;
		}
		if(op == "!=")
		{
			mcode << "slt	$t3,$t1,$t2" << endl;
			mcode << "slt	$t4,$t2,$t1" << endl;
			mcode << "or	$t0,$t3,$t4" << endl;
		}
		if(ret != def)
		{
			ret = "_"+ret;
			mcode << "sw	$t0, " << ret << endl;
			if(vars.find(ret) == vars.end())
						vars[ret] = 1;
		}
	}
}

void data()
{
	string s;
	f << ".data" << endl;
	for(map<string,int> :: iterator i = vars.begin(); i != vars.end();i++)
		f << i->first << ":		.word 0" << endl;
	ifstream fin("mipsinter.s");
	while(getline(fin,s))
		f << s << endl;
}