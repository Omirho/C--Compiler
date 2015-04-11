ofstream tcode("threecode.txt");
string def = "";
string newlabel()
{
	static int c = 0;
	stringstream ss;
	ss << ++c;
	return "label_" + ss.str();
}

string newtemp()
{
	static int c = 0;
	stringstream ss;
	ss << ++c;
	return "temp_" + ss.str();
}

vector<string> breaks;
vector<string> continues;

string generatecode(ttnode *t)
{
	if(t->identifier == "main_function")
	{
		tcode << "main" << ":" << endl;
		string a = generatecode(t->first);
		return def;
	}
	if(t->identifier == "variable")
	{
		return t->first->item;
	}
	if(t->identifier == "statement")
	{
		if(t->item == "break")
			tcode << "goto " << breaks.back() << endl;
		if(t->item == "continue")
			tcode << "goto " << continues.back() << endl;
		else
			string a = generatecode(t->first);
		return def;
	}
	if(t->identifier == "condition_stat")
	{
		string start = newlabel();
		string end = newlabel();
		string a = generatecode(t->first);
		tcode << "if " << a << " goto " << start << endl;
		tcode << "goto " << end << endl;
		tcode << start << ":" << endl;
		string b = generatecode(t->second);
		tcode << end << ":" << endl;
		if(t->item == "op")
		{
			string c = generatecode(t->third);
		}
		return def;
	}
	if(t->identifier == "for_loop")
	{
		string start = newlabel();
		string middle = newlabel();
		string con = newlabel();
		string end = newlabel();
		string a = generatecode(t->first);
		string b = generatecode(t->second);
		string temp = newtemp();
		breaks.push_back(end);
		continues.push_back(con);
		tcode << a << " = 0" << endl;
		tcode << start << ":" << endl;
		tcode << temp << " = " << a << " < " << b << endl;
		tcode << "if " << temp << " goto " << middle << endl;
		tcode << "goto " << end << endl;
		tcode << middle << ":" << endl;
		string c = generatecode(t->third);
		tcode << con << ":" << endl;
		tcode << temp << " = " << a << " + 1" << endl;
		tcode << a << " = " << temp << endl;
		tcode << "goto " << start << endl;
		tcode << end << ":" << endl;
		breaks.pop_back();
		continues.pop_back();
		return def;
	}
	if(t->identifier == "while_loop")
	{
		string start = newlabel();
		string middle = newlabel();
		string end = newlabel();
		breaks.push_back(end);
		continues.push_back(start);
		tcode << start << ":" << endl;
		string a = generatecode(t->first);
		tcode << "if " << a << " goto " << middle << endl;
		tcode << "goto " << end << endl;
		tcode << middle << ":" << endl;
		string b = generatecode(t->second);
		tcode << "goto " << start << endl;
		tcode << end << ":" << endl;
		breaks.pop_back();
		continues.pop_back();
		return def;
	}
	if(t->identifier == "return_stat")
	{
		if(t->item == "op")
		{
			string a = generatecode(t->first);
			tcode << "return " << a << endl;
		}
		else
		{
			tcode << "return " << endl;
		}
		return def;
	}
	if(t->identifier == "read")
	{
		string a = generatecode(t->first);
		tcode << "read " << a << endl;
		return a;
	}
	if(t->identifier == "write")
	{
		string a = generatecode(t->first);
		tcode << "write " << a << endl;
		return a;
	}
	if(t->identifier == "expression")
	{
		if(t->item == "=")
		{
			string a = generatecode(t->second);
			string b = generatecode(t->first);
			string ret = newtemp();
			tcode << b << " = " << a << endl;
			return b;
			tcode << ret << " = " << b << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "logic_expression")
	{
		if(t->item == "or")
		{
			string a = generatecode(t->second);
			string b = generatecode(t->first);
			string ret = newtemp();
			tcode << ret << " = " << b << " || " << a << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "and_expression")
	{
		if(t->item == "and")
		{
			string a = generatecode(t->second);
			string b = generatecode(t->first);
			string ret = newtemp();
			tcode << ret << " = " << b << " && " << a << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "relation_expression")
	{
		if(t->item == "op")
		{
			string a = generatecode(t->third);
			string b = generatecode(t->first);
			string c = generatecode(t->second);
			string ret = newtemp();
			tcode << ret << " = " << b << " " << c << " " << a << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "simple_expression")
	{
		if(t->item == "op")
		{
			string a = generatecode(t->third);
			string b = generatecode(t->first);
			string c = generatecode(t->second);
			string ret = newtemp();
			tcode << ret << " = " << b << " " << c << " " << a << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "mul_expression")
	{
		if(t->item == "op")
		{
			string a = generatecode(t->third);
			string b = generatecode(t->first);
			string c = generatecode(t->second);
			string ret = newtemp();
			tcode << ret << " = " << b << " " << c << " " << a << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "unary_expression")
	{
		if(t->item == "op")
		{
			string a = generatecode(t->second);
			string b = generatecode(t->first);
			string ret = newtemp();
			tcode << ret << " = " << b << a << endl;
			return ret;
		}
		else
		{
			return generatecode(t->first);
		}
	}
	if(t->identifier == "climax")
	{
		return generatecode(t->first);
	}
	if(t->identifier == "constants")
	{
		return t->first->item;
	}
	if(t->identifier == "call")
	{
		//return t->first->item;
	}
	if(t->identifier == "op1")
	{
		return t->first->item;
	}
	if(t->identifier == "op2")
	{
		return t->first->item;
	}
	if(t->identifier == "op3")
	{
		return t->first->item;
	}
	if(t->identifier == "unary_op")
	{
		return t->first->item;
	}
	else
	{
		if(t->first != NULL)
			generatecode(t->first);
		if(t->second != NULL)
			generatecode(t->second);
		if(t->third != NULL)
			generatecode(t->third);
		return def;
	}
}