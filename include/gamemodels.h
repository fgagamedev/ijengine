#ifndef GAME_MODELS_H
#define GAME_MODELS_H

#include <vector> 
#include <map>
using namespace std;
namespace ijengine {
	struct Model{
		unsigned int vao;
      	vector<unsigned int> vbos;
        Model(){}
	};
	class GameModels{
	public:
		GameModels();
		~GameModels();
		virtual CreateTriangleModel(const string& gameModelName);
		virtual DeleteModel(const string& gameModelName);
		unsigned int GetModel(const string& gameModelName);
	private:
		map<string,Model>GameModelList;
	};
}

#endif
