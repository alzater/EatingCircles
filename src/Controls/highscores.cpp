void loadHighscoresFromFile(std::vector<Highscore>& data){
	file::handle h = file::open("SETTINGS_FILE_NAME", "rb");
	char buf[256] = {0};
	std::string setting;
	int value;
	file::read(h, buf, sizeof(buf));
	file::close(h);
	stringstream ss;
	ss << buf;
	while(ss >> setting >> value)
	{
		data[setting] = value;
		log::messageln("read %s: %d", setting.c_str(), value);
	}
}

void saveHighscoresToFile(std::vector<Highscore>& data){
	char buf[256];
	buf[0] = 0;
	for(auto it : data)
	{
		sprintf(&buf[strlen(buf)], "%s %d\n", it.first.c_str(), it.second);
	}
	file::handle h = file::open("SETTINGS_FILE_NAME", "wb");
	log::messageln("writing into %s: %s", "SETTINGS_FILE_NAME", buf);
	file::write(h, buf, strlen(buf));
	file::close(h);
}
