class param
{
	public:
		Type type;
		string name;
		param(string nm): name(nm), type(t_int) {}
		param(string nm, Type t): name(nm), type(t) {}
		string genKey()
		{
			return name + "." + "func";
		}
};

class symbol
{
public:

    std::string name;
    Type type, ret_type;
	int scope, param_count;
	vector<param> paras;
	symbol(string nm): name(nm), type(t_int), param_count(0), ret_type(t_none){}
	symbol(string nm, Type t): name(nm), type(t), param_count(0), ret_type(t_none){}
    symbol(string nm, Type t, int Scope): name(nm), scope(Scope), type(t), ret_type(t_none), param_count(0) {}
	symbol(string nm, Type t, vector<param> p): name(nm), paras(p), type(t), ret_type(t_none), param_count(p.size()) {}
    symbol(string nm, Type t, Type rt, int Scope): name(nm), scope(Scope), type(t), ret_type(rt), param_count(0) {}
	symbol(string nm, Type t, Type rt, vector<param> p): name(nm), paras(p), type(t), param_count(p.size()), ret_type(rt) {}
	
	string genKey()
	{
		string Types[] = {"none", "int", "float", "bool", "func"};
		stringstream ss;
		ss << scope;
		return name + "." + Types[type] + "." + ss.str();
	}
};

class symtable
{
    int scope;
    vector < map < string, symbol > > table, back_tab;
public:
    symtable(): scope(1) { table.push_back(map<string,symbol>());}

    symbol lookupX(string id)
    {
        for(int i = scope; i > 0; --i)
            if(table[i-1].count(id))
                return table[i-1].find(id)->second;
        return symbol(string());
    }
	
	string lookup(string id)
	{
		symbol temp = lookupX(id);
		if(temp.name == string()) return string();
		return temp.genKey();
	}

	bool lookup_curscope(string id)
	{
		return table[scope-1].count(id);
	}
	
    void add_scope()
    {
        table.push_back(map<string,symbol>());
        scope++;
		//add_var(symbol("__dabba_var", t_none));
    }

    void remove_scope()
    {
        table.pop_back();
        scope--;
    }

	void add_var(symbol s)
	{
		s.scope = scope;
		table[scope-1].insert(make_pair(s.name, s));
	}

	vector<string> getparams(string id)
	{
		assert(table[0].count(id) > 0);
		symbol func = table[0].find(id)->second;
		vector<string> r;
		for(int i = 0; i < func.param_count; ++i)
		{
			r.push_back(symbol (func.paras[i].name, func.paras[i].type, func.scope + 1).genKey());
		}
		return r;
	}
	
	bool lookupfunc(string id)
	{
		for(int i = scope; i > 0; --i)
			for(map < string, symbol > :: iterator it = table[i-1].begin(); it != table[i-1].end(); it++)
				if(it -> first.find_first_of('.') != string :: npos and id == it -> first.substr(0,it -> first.find_first_of('.')))
					return true;
        return false;
	}
	
	vector<Type> getparamtype(string id)
	{
		assert(table[0].count(id) > 0);
		symbol func = table[0].find(id)->second;
		vector<Type> r;
		for(int i = 0; i < func.param_count; ++i)
		{
			r.push_back(func.paras[i].type);
		}
		return r;
	}
	
	vector<string> backup()
	{
		vector<string> back_var;
		back_tab = table;
		for(int i = 2; i <= scope; i++)
			for(map<string,symbol>::iterator it = table[i-1].begin(); it != table[i-1].end(); ++it)
				back_var.push_back(it -> second.genKey());
		for(int i = scope ; i > 1; i--)
			table.pop_back();
		scope = 1;
		return back_var;
	}
	
	Type getType(string s)
	{
		string Types[] = {"none", "int", "float", "bool", "func"};
		for(int i = 0; i < 5; ++i)
		{
			if(s == Types[i])
				return static_cast<Type>(i);
		}
		return t_none;
	}
	
	string typetostring(Type t)
	{
		string Types[] = {"none", "int", "float", "bool", "func"};
		return Types[t];
	}
	
	void restore(vector<string> back_var)
	{
		table = back_tab;
		scope = table.size();
	}
};
