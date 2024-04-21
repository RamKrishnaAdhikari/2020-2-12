#include"header.h"
#include <iostream>

using namespace std;
Exif:: Exif():Herstellername("N/A"),Modellbezeichnung("N/A"),Wert(false){}
Exif:: Exif(const std:: string& herstellername,const std::string& modellbezeichnung,bool wert)
    :Herstellername(herstellername),Modellbezeichnung(modellbezeichnung),Wert(wert){}
std::string Exif::getherstellername()const{
    return Herstellername;
}
std::string Exif:: getmodellbezeichnung()const{
    return Modellbezeichnung;
}
bool Exif::getwert ()const{
    return Wert;
}
Image:: Image(const std::string& bildtitel):Bildtitel(bildtitel),I(nullptr){}
Image:: Image(const std::string& bildtitel,const Exif& newi):Bildtitel(bildtitel),I(new Exif(newi)){}
Image::~Image(){
    delete I;
}
bool Image::hasExif()const{
    return(I!=nullptr);
}
const Exif* Image::getexif()const{
    return I;
}
std::string Image:: getbildtitel()const{
    return Bildtitel;
}
const std::vector<Image>& Imageviewer:: getimage()const{
    return  images;
}
void  Imageviewer::addimage(const Image& i){
    images.push_back(i);
}
bool Imageviewer::empty()const{
    return images.empty();
}
void  Imageviewer::Imagedetail()const{
    if(!empty()){
        for(const auto& image:images){
            cout<<"Bildtitel:"<<image.getbildtitel();
            const Exif* exif = image.getexif();
            if(exif){
                cout<<"Herstellername:"<<exif->getherstellername()<<endl;
                cout<<"Modellbezeichnung :"<<exif->getmodellbezeichnung()<<endl;
                cout<<"Wert :"<<exif->getwert()<<endl;
            }
            else{
                cout<<"Exif daten doesnot exist "<<endl;
            }

        }
    }

}
bool Imageviewer::removeImage(const std::string& Bildtitel){
    for(auto image=images.begin();image!=images.end();image++){
        if(image->getbildtitel()==Bildtitel){
            cout<<"Image should be erased"<<endl;
            images.erase(image);
            return true;
        }
    }
    return false;
}

void Imageviewer::addalbum(const std::string& n){
    for(const auto& a:album){
        if(a.getname()==n){
            throw  std:: invalid_argument("Das existiert schon");
        }
    }

    Album newalbum(n);
    album.push_back(newalbum);

  }
void Imageviewer:: listalbum(){
    for( auto& a:album){
        cout<<a.getname()<<endl;
        cout<<a.getimageinalbum().size();


}
}
void Imageviewer::addimageinalbum(const std::string& imagename,const std::string& albumname){
    Image* imagetoadd = nullptr;
    for( auto& i : images){
        if(i.getbildtitel()==imagename){
            imagetoadd = &i;
            for( auto& a:album){
                if(a.getname()==albumname){
                    a.getimageinalbum().push_back(imagetoadd);
                    return;
                }
            }
        }

    }
    throw std::invalid_argument("Bild and album doesnot exist");

    }
void Imageviewer::showalbum (const std::string& albumname){
    for( auto& a : album){
        if(a.getname()==albumname){
            cout<<"Album name: "<<a.getname()<<endl;
            for(const auto i :a.getimageinalbum()){
                cout<<"Bildtitel:"<<i->getbildtitel();
                const Exif*j=i->getexif();
                if(j){
                    cout<<"Herstellername :"<<j->getherstellername()<<endl;
                    cout<<"Modellbezeichnung :"<<j->getmodellbezeichnung()<<endl;
                    cout<<"wert:"<<j->getwert()<<endl;
                }
                else{
                    cout<<"Exif doesnot exist"<<endl;
                }

            }
            return;
        }

    }
    throw std::invalid_argument("Album doesnot exist");

    }

Album::Album(const std::string& name):Name(name){}
std::string Album:: getname()const{
    return Name;
}
 std::vector<Image*> Album::getimageinalbum(){
    return iminalbum;
}

