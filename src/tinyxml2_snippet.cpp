#include <tinyxml2.h>
#include <iostream>

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

void parsingXMLString()
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

/*
<root>
    <id lang="en">0</id>
    <id lang="en">1</id>
    <id lang="en">2</id>
</root>
*/

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

void queryElements()
{
    //Once we have the desired element, we can access the data (text/attribute) inside
    std::string xmlDocPath="../data/XML_database/bookshop.xml";
    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile(xmlDocPath.c_str());
    int ISBN;
    double price;
    const char* lang;
    lang=xmlDoc.FirstChildElement("shop")->FirstChildElement("book")->FirstChildElement("title")->Attribute("lang");
    xmlDoc.FirstChildElement("shop")->FirstChildElement("book")->FirstChildElement("ISBN")->QueryIntText(&ISBN);
    xmlDoc.FirstChildElement("shop")->FirstChildElement("book")->FirstChildElement("price")->QueryDoubleText(&price);
    std::cout<<lang<<"\n";
    std::cout<<"ISBN:"<<ISBN<<"\n";
    std::cout<<"price:"<<price<<"\n";






}

int main(int argc, char** argv)
{
    queryElements();
}
