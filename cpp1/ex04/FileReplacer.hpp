#ifndef __FILE_REPLACER_HPP__
#define __FILE_REPLACER_HPP__
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <exception>

class FileReplacer {
	
	private:
		std::string _source_file;
		std::string _pattern;
		std::string _replace;
		const std::string	readSrcFile(const std::ifstream&);
		const std::string	replaceAll(const std::string&);
		void				writeDestFile(const std::string&);

	public:
		FileReplacer(const std::string& src_file, const std::string& pattern, const std::string& replace);
		bool	run();
};

#endif
