enum Type
{
    t_none,
    t_int,
    t_float,
	t_bool,
    t_func
};

class ttnode
{
public:
	string item,identifier,name;
	Type type;
	int line_num;
	ttnode *first, *second, *third;
	ttnode() 
	{ 
		item.clear(); 
		identifier.clear(); 
		name.clear(); 
		first = second = third = NULL; 
	}
	
};
