#ifndef GUARD_PIC_H
#define GUARD_PIC_H

#include <vector>
#include <string>

std::string::size_type  width(const std::vector<std::string>& v);
std::vector<std::string> frame(const std::vector<std::string>& v);
std::vector<std::string> vcat(const std::vector<std::string>& top,
			      const std::vector<std::string>& bottom);

std::vector<std::string> hcat(const std::vector<std::string>& left, 
			      const std::vector<std::string>& right);

#endif
