# Algorithms Illuminated

Примеры алгоритмов из книги "Algorithms Illuminated" Tim Roughgarden. Реализованы на C++ для точного управления памятью.

## Запуск

Для сборки и запуска необходимо установить [Clang](https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8) и [Visual Code](https://code.visualstudio.com/download). Собранный .exe файл можно найти в папке *output* независимо от способа сборки.

Запуск из Visual Code:

- Открыть .cpp файл
- Нажать F5

Запуск из command line:

- Поправить название .cpp файла в скрипте rum.bat
- Запустить run.bat

## References

- [Описание алгоритмов](./part-1/README.md.md)  
  Короткое описание алгоритмов и реализация на С++
- [CLang](https://clang.llvm.org/)  
   Компиляторы для семейства языков C на основе LLVM  
   *clang.exe* - gcc совместимый компилятор  
   *clang-cl.exe* - MSVC совместимый компилятор  
- [LVVM](https://llvm.org/)  
  Инфраструктура для компиляторов, которая включает генераторы и оптимизаторы кода.
- [CLang manual](https://clang.llvm.org/docs/UsersManual.html)  
  Описание параметров утилиты *clang.exe*
