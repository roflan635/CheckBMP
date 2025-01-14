// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"
#include <fstream>

#pragma pack (push,1) // обязательно выключаем выравнивание элементов структур по умолчанию
struct BitmapFileHeader
{
    char  bfType[2];  // сигнатура файла "BM"
    unsigned long bfSize; // размер файла в байтах
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned long bfOffBits; // смещение относительно начала файла в байтах, где располагаются растровые данные
};
struct BitmapInfoHeader
{
    unsigned long biSize; // размер структуры BitmapInfoHeader == 40 байт
    long biWidth;
    long biHeight; // высота изображения в пикселах
    unsigned short biPlanes; // число цветовых планов == 1
    unsigned short biBitCount; // число бит на пиксель
    unsigned long biCompression; // тип сжатия изображения
    unsigned long biSizeImage; //размер растрового изображения в байтах
    long biXPelsPerMeter;  // разрешение изображения по ширине
    long biYPelsPerMeter;  // разрешение изображения по высоте
    unsigned long biClrUsed; // число испольщуемых цветов изображения, если == 0, то используются все доступные цвета
    unsigned long biClrImportant;  // число важных цветов изображения
};
#pragma pack(pop)


bool CheckBMP(std::string fileName)
{
    BitmapFileHeader BFH; // объявляем переменную для хранения заголовка BitmapFileHeader
    BitmapInfoHeader BIH; // объявляем переменную для хранения заголовка BitmapInfoHeader
    std::ifstream f(fileName, std::ios::binary); // открываем для фтения файл в бинарном режиме
    if (!f) // если файл не открыт
        return false; // выходим с отрицательным результатом
    f.read((char*)&BFH, sizeof(BitmapFileHeader)); // читаем из файла заголовок BitmapFileHeader в переменную BFH
    f.read((char*)&BIH, sizeof(BitmapInfoHeader));       // читаем из файла заголовок BitmapInfoHeader в переменную BIH
}

/*
	Разместите в данном файле функцию, которая проверяет корректность BMP файла, имя которого передается
	ей в качестве параметра


	1. Функция должна иметь имя CheckBMP
	2. Функция в качестве параметров должна принимать следующее:
		- первый параметр - Имя файла, строковый тип std::string
	3. Функция должна возвращать true, если переданный файл является файлом Windows bitmap
	и false в противном случае

	!!!!! ВАЖНО !!!!!
	В данном файле разрешается разместить кроме кода требуемой функции - код любых других вспомогательных
	функций. Никакой функции main() в этом файле быть не должно.
	Если вы хотите испытать и отладить вашу функцию - пишите код в файле Example.cpp проекта Example данного решения
	Для этого задайте в качестве запускаемого проекта проект Example.

	ДЛЯ АВТОМАТИЧЕСКОГО ТЕСТИРОВАНИЯ  проверки правильности работы вашего задания - сделайте запукаемым проект
	Tests и запустите его. Если функция написана правильно - все тесты должны успешно выполниться
	(зеленый цвет в консоли). Если ваша функция работает некорректно - в консоли будут сообщения красным цветом
*/
