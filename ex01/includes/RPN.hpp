#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>
# include <stdexcept>

# define GREEN	"\x1B[0;92m"
# define YELLOW	"\x1B[0;93m"
# define BLUE	"\x1B[0;94m"
# define PINK	"\x1B[0;95m"
# define CYAN	"\x1B[0;96m"
# define WHITE	"\x1B[38;5;15m"
# define GREY	"\x1B[38;5;8m"
# define ORANGE	"\x1B[38;5;202m"
# define RED	"\x1B[38;5;160m"
# define RESET	"\033[0m"

int RPN(std::string equation);

#endif