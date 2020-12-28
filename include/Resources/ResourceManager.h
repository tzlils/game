#pragma once
#include <Resources/Texture2D.h>
#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <Resources/ShaderProgram.h>
#include <map>
#include <string>
#include <memory>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>


using namespace std;

class IResourceSet {
public:
	virtual ~IResourceSet() = 0;
};
IResourceSet::~IResourceSet() {}

template <typename T>
class CResourceSet : public IResourceSet {
public:
	~CResourceSet(){}
	unordered_map<string, T> resources;
};

class ResourceManager {
	public:
		ResourceManager();

		template <typename T>
		T &get (string name) {
			return reinterpret_cast<CResourceSet<T>&>(
				*sets[type_index(typeid(T))]
			).resources[name];
		}

		template <typename T>
		void set (string name, T resource) {
			auto it = sets.find(type_index(typeid(T)));
			if (it == sets.end()) {
				 sets.emplace(std::type_index(typeid(T)), unique_ptr<IResourceSet>((IResourceSet*)new CResourceSet<T>()));
				 it = sets.find(type_index(typeid(T)));
			}

			reinterpret_cast<CResourceSet<T>&>(*it->second).resources.emplace(std::make_pair(name, resource));
		}
	private:
		unordered_map<type_index, unique_ptr<IResourceSet>> sets;
};