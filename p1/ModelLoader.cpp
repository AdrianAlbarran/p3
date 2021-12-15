#include "ModelLoader.h"


void ModelLoader::LoadModel(const string& filePath)
{
	try
	{
		ifstream objFile(filePath);
		if (objFile.is_open())
		{
			string line;
			int count = 0;
			while (getline(objFile, line))
			{
				if (line[0] == 'v' && line[1] == 'n')
				{
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normVertex.push_back(normal);
				}
				else if (line[0] == 'v')
				{
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertVertex.push_back(vertex);
				}
				else if (line[0] == 'f')
				{
					Triangle triangle = this->parseObjTriangle(line);
					//this->model.addTriangle(this->center(triangle));
					this->model.addTriangle(triangle);
				}
			}
			objFile.close();
		}
		else
		{
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}
	}
	catch (exception& ex)
	{
		cout << "Excepcion al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

Vector3D ModelLoader::parseObjLineToVector3D(const string& sa) 
{
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(sa);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * this->getScale();
}

Triangle ModelLoader::parseObjTriangle(const string& sa) 
{
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(sa);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->vertVertex[idxVertex0 - 1];
	Vector3D vertex1 = this->vertVertex[idxVertex1 - 1];
	Vector3D vertex2 = this->vertVertex[idxVertex2 - 1];
	Vector3D normal = this->normVertex[idxNormal0 - 1];

	Triangle parsedTriangle(vertex0, normal, vertex1, normal, vertex2, normal);

	return parsedTriangle;;
}

void ModelLoader::calcBoundaries(Vector3D vectorPoint) 
{
	this->maxX = fmax(this->maxX, vectorPoint.getX());
	this->maxY = fmax(this->maxY, vectorPoint.getY());
	this->maxZ = fmax(this->maxZ, vectorPoint.getZ());
	this->minX = fmax(this->minX, vectorPoint.getX());
	this->minY = fmax(this->minY, vectorPoint.getY());
	this->minZ = fmax(this->minZ, vectorPoint.getZ());

}

Triangle ModelLoader::center(Triangle triangle) 
{
	Vector3D modelCenter(this->minX + this->getWidth() / 2.0,
		this->minY + this->getHeight() / 2.0,
		this->minZ + this->getLength() / 2.0);

	Triangle centeredTriangle(
		triangle.getVert1() - modelCenter,
		triangle.getVert2() - modelCenter,
		triangle.getVert3() - modelCenter,
		triangle.getNormal1(),
		triangle.getNormal2(),
		triangle.getNormal3());
	return centeredTriangle;
}

void ModelLoader::Clear()
{
	vertVertex.clear();
	normVertex.clear();
	model.clear();
}