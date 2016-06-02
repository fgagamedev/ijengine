#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <vector> 
#include <map>
using namespace std;
namespace ijengine {
	struct Model{
		unsigned int vao;
      	vector<unsigned int> vbos;
        Model(){}
	};
	class Triangles : public GameModels{
	public: 
		Triangles();
		~Triangles();
		 CreateTriangleModel(const string& gameModelName);
		 DeleteModel(const string& gameModelName);
		unsigned int GetModel(const string& gameModelName);
	private:
		map<string,Model>GameModelList;
	};
}

#endif
