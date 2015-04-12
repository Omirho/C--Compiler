enum Type
{
    t_none,
    t_int,
    t_float,
	t_bool,
    t_func
};

class symbol
{
public:

    std::string name, val;
    Type type;
	int scope, param_count;
    symbol(string nm, string v, Type t): name(nm), val(v), type(t) {}
    symbol(string nm): name(nm), val(string()), type(t_int) {}
	string genKey()
	{
		stringstream ss;
		ss << scope;
		return name + "." + type + "." + ss.str();
	}
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
		table[scope-1].insert(make_pair(s.name, s));
	}
	
	vector<string>
};
