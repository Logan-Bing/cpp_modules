#include "FileReplacer.hpp"

#define ERROR_OPPENING_FILE "Error: can't open the file"
#define ERROR_READING_FILE "Error: read the file"

FileReplacer::FileReplacer(const std::string& src_file, 
							const std::string& pattern, 
							const std::string& replace): _source_file(src_file), _pattern(pattern), _replace(replace)
{}

bool	FileReplacer::run(void)
{
	std::ifstream fs(this->_source_file);
	try 
	{
		if (!fs.is_open()) throw std::runtime_error(ERROR_OPPENING_FILE);
		std::string src = readSrcFile(fs);
		std::string dest = replaceAll(src);
		writeDestFile(dest);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
		// fs.close();
		return (false);
	}
	fs.close();
	return (true);
}

const std::string FileReplacer::readSrcFile(const std::ifstream& fs)
{
	if (fs.bad()) throw std::runtime_error(ERROR_READING_FILE);

	std::ostringstream content; 
	content << fs.rdbuf();
	return (content.str());
}

const std::string	FileReplacer::replaceAll(const std::string& src)
{
	std::string dest("");
	int pos(0);
	size_t found;
	while ((found = src.find(this->_pattern, pos)) != std::string::npos)
	{
		dest += src.substr(pos, found - pos);
		dest += this->_replace;
		pos = found + this->_pattern.length();
	}
	dest += src.substr(pos);
	return (dest);
}

void	FileReplacer::writeDestFile(const std::string& dest)
{
	std::string dest_file(this->_source_file + ".replace");
	std::ofstream fs(dest_file);
	
	if (!fs.is_open()) throw std::runtime_error(ERROR_OPPENING_FILE);
	fs << dest;
}
