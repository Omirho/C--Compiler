enum Type
{
    t_none,
    t_int,
    t_float,
	t_bool,
    t_func
};

class param
{
	public:
		Type t;
		string name;
		string genKey()
		{
			return name + "." + type + "." + "func";
		}
}

class symbol
{
public:

    std::string name, val;
    Type type;
	int scope, param_count;
	vector<param> paras;
    symbol(string nm, string v, Type t): name(nm), val(v), type(t) {}
    symbol(string nm): name(nm), val(string()), type(t_int) {}
	string genKey()
	{
		stringstream ss;
		ss << scope;
		return name + "." + type + "." + ss.str();
	}
	symbol(string nm, Type t, vector<param>& p): name(nm), paras(p), type(t), val(string()), param_count(p.size()) {}
};

class symtable
{
    int scope;
    vector < map < string, symbol > > table;
public:
    symtable(): scope(1) {}

    string lookup(string id)
    {
        for(int i = scope; i > 0; --i)
            if(table[i-1].count(id))
                return table[i-1][id].genKey();
        return string();
    }

    int add_scope()
    {
        table.push_back(map<string,symbol>());
        scope++;
    }

    int remove_scope()
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
		symbol func = table[1][id];
		vector<string> r;
		for(int i = 0; i < func.param_count; ++i)
		{
			r.push_back(func.paras[i]);
		}
		return r;
	}
	
	vector<string> backup()
	{
		vector<string> back_var;
		for(int i = 2; i <= scope; i++)
			for(map<string,symbol>::iterator it = table[i-1].begin(); it != table[i-1].end(); ++it)
				back_var.push_back(it -> genKey());
		
		for(int i = scope; i > 1; i--)
			table.pop_back();
	}
};
