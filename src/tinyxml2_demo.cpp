#include <tinyxml2.h>
#include <string>
#include <iostream>

/*
Refs: https://shilohjames.wordpress.com/tag/tinyxml2/
XMLDocument acts as a container for a collection of XMLElements, and is the primary interface for saving to and loading from XML files.
XMLElement is a container for a single XML element, including any attributes.
XMLNode is a base class of both XMLElement & XMLDocument, and provides the interface required for traversal of elements within a document.
*/


void parseXMLDoc()
{
    std::string xmlString =R"(
	<information>
		<attributeApproach value='10' />
		<textApproach>
			<index>2</index>
		</textApproach>
	</information>)";
	tinyxml2::XMLDocument docFromString;
	if (docFromString.Parse(xmlString.c_str()) == tinyxml2::XML_SUCCESS)
	{
		docFromString.SaveFile("information.xml");
	}
}

void iteratingElements()
{
    
    std::string xmlDocPath="../data/XML_database/bookshop.xml";
    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile(xmlDocPath.c_str());
    
    tinyxml2::XMLElement* root = xmlDoc.FirstChildElement("shop");
    for(tinyxml2::XMLElement* e = root->FirstChildElement("book"); e != NULL; e = e->NextSiblingElement("book"))
    {
        std::cout<< e->FirstChildElement("title")->GetText()<<"\n";
    }
}

void creatingXMLDoc()
{
    tinyxml2::XMLDocument xmlDoc;
    tinyxml2::XMLNode* root = xmlDoc.NewElement("root");

    //we must explicitly attach it to the XMLDocument
    xmlDoc.InsertFirstChild(root);

    for(int i=0;i<3;i++)
    {
        tinyxml2::XMLElement* book =xmlDoc.NewElement("id");
        book->SetText(std::to_string(i).c_str());
        book->SetAttribute("lang","en");
        root->InsertEndChild(book);
    }
    xmlDoc.SaveFile("created_doc.xml");
}

void readingXMLDoc()
{
    std::string xmlDocPath="../data/XML_database/bookshop.xml";
    tinyxml2::XMLDocument xmlDoc;
    tinyxml2::XMLError result = xmlDoc.LoadFile(xmlDocPath.c_str());
    if(result!= tinyxml2::XML_SUCCESS)
    {
        std::cout<<"Error reading XML\n";
    }
}

void queryElements()
{
    //Once we have the desired element, we can access the data (text/attribute) inside
    std::string xmlDocPath="../data/XML_database/bookshop.xml";
    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile(xmlDocPath.c_str());
    int ISBN;
    double price;
    const char * lang;
    lang=xmlDoc.FirstChildElement("shop")->FirstChildElement("book")->Attribute("lang");
    xmlDoc.FirstChildElement("shop")->FirstChildElement("book")->FirstChildElement("ISBN")->QueryIntText(&ISBN);
    xmlDoc.FirstChildElement("shop")->FirstChildElement("book")->FirstChildElement("price")->QueryDoubleText(&price);

    std::cout<<"ISBN:"<<ISBN<<"\n";
    std::cout<<"price:"<<price<<"\n";
    std::cout<<"lang:"<<lang<<"\n";





}

int main(int argc, char** argv)
{
//    parseXMLDoc();
//    iteratingElements();
//    creatingXMLDoc();
    queryElements();
}

