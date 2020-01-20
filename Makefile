hellomake: helloworld.cpp
	g++ -o hellomake helloworld.cpp

1: 1_const_qualifier.cpp
	g++ -o 1_const_qualifier 1_const_qualifier.cpp
	./1_const_qualifier
	
2: 2_constexpr_qualifier.cpp
	g++ -o 2_constexpr_qualifier 2_constexpr_qualifier.cpp
	./2_constexpr_qualifier

3: 3_basic_templates.cpp
	g++ -o 3_basic_templates 3_basic_templates.cpp
	./3_basic_templates

clean:
	rm 1_const_qualifier
	rm 2_constexpr_qualifier
	rm 3_basic_templates