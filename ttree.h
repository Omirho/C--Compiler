class ttnode
{
public:
	string item,identifier,name;
	ttnode *first, *second, *third;
	ttnode() 
	{ 
		item.clear(); 
		identifier.clear(); 
		name.clear(); 
		first = second = third = NULL; 
	}
	
};
