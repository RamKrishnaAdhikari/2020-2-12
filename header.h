#ifndef HEADER_H
#define HEADER_H
#include<string>
#include<vector>

class Exif{
private:
    std::string Herstellername;
    std::string Modellbezeichnung;
    bool Wert;
    std::string Datumangabe;
public:
    Exif();
    Exif(const std::string& herstellername,const std::string&modellbezeichnung,bool wert);
    std::string getherstellername()const;
    std::string getmodellbezeichnung()const;
    bool getwert()const;

};
class Image{
    private:
    std::string Bildtitel ;
        Exif* I ;
public:
        Image(const std::string& bildtitel);
    Image(const std::string& bildtitel, const Exif& newi);
        ~Image();
    bool hasExif()const;
        std:: string getbildtitel()const;
   const Exif* getexif()const;

};
class Album;
class Imageviewer{
private:
    std::vector<Image> images;
    std::vector<Album>album;

public:
    const std::vector<Image>& getimage()const;
    void addimage(const Image& i);
    bool empty()const;
    void Imagedetail()const;
    bool removeImage(const std::string& Bildtitel);
    void addalbum(const std::string& n);
    void listalbum();
    void addimageinalbum(const std::string& imagename,const std::string& albumnamegetname);
    void showalbum(const std::string& albumname) ;
};
class Album{
private:
    std::string Name;
    std::vector<Image*>iminalbum;
public:
    Album(const std::string& name);
    std::string getname()const;
     std::vector<Image*>getimageinalbum();

};


#endif // HEADER_H
