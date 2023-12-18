
#include	<string>


#ifndef CLASS_ScalarConverter
# define CLASS_ScalarConverter

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		~ScalarConverter();
		ScalarConverter &operator= (const ScalarConverter& a);
	public:
		void			static convert(std::string arg);
};

#endif
