# Введение в разработку в ОС Linux

Практика показывает, что разработка больших программных проектов на C, C++ и языках ассемблера наиболее просто организуется в OC Linux.

Цели данного материала:
- Гайд по установке ОС Linux;
- Настройка окружения;
- Памятка по основным командам консоли;

Комментарий:
- Вести разработку можно и с MacOS, но преподавательская поддержка будет слабее.

## Установка Linux

Существуют три варанта:
1. Установка Linux как основной или второй (dual-boot) системы.
2. Запуск ОС Linux в виртуальной машине.
3. Запуск WSL (Window Subsystem for Linux).

### Запуск ОС Linux на железе

Полезные ссылки:
- [Последовательность установки Ubuntu Linux](https://ubuntu.com/tutorials/install-ubuntu-desktop#1-overview).
- [Последовательность установки Linux Mint](https://linuxmint-installation-guide.readthedocs.io/en/latest/).

### Запуск ОС Linux в виртуальной машине

1. Разрешение виртуализации из загрузчика и хостовой ОС.

Для использования виртуализации в хостовой ОС её поддержку сначала надо включить.
Этот процесс зависит от загрузчика ОС (BIOS), от установленной ОС и модели компьютера.
[Хоткеи для входа в BIOS от разных производителей](https://www.tomshardware.com/reviews/bios-keys-to-access-your-firmware,5732.html)

2. Установка ПО для виртуализации.

Рекомендуемое ПО - [VirtualBox](https://www.virtualbox.org/wiki/Downloads).

3. Выбор образа госевой ОС.

Рекомендуемый образ - [VM-образ Ubuntu Linux c официального сайта](https://xubuntu.org/download/).

4. Создание новой виртуальной машины.

На этом этапе необходимо указать к образу и выбрать его тип (ОС Linux, Ubuntu 64-bit).
Рекомендуемый объём RAM виртуальной машины - половина полного объёма RAM (2+ Гб).
Минимальный рекомендуемый размер виртуального жёсткого диска - 25+ Гб.

5. Конфигурация виртуальной машины.

В настройках виртуальной машины требуется:
- В пункте `General->Advanced`:
	- Включить общий буфер обмена и Drag'n'drop (для удобства);
- В пункте `System->Motherboard`:
	- Установить рекомендуемое кол-во ядер, передаваемых виртуальной машине - половина от имеющихся;
- В пункте `System->Processor`:
	- Установить максимальная загрузка CPU в 100%;
	- Убедиться, что галочка в пункте `Enable Nested VT-X/AMD-V` выставлено (иначе - см. этап (1)).
- В пунтке `Display`:
	- Установить размер видеопамяти в максимальный возможный;
	- Установить галочку около `3D Acceleration`.

Также рекомендуется ознакомиться с shortcut-ом "вынести курсор из виртуальной машины", чтобы не пасть заложником виртуального мира (обычно это правый ctrl). 

6. Первый запуск виртуальной машины

При запуске необходимо указать путь к загруженному файлу загрузочного образа Ubuntu.

Первый запуск VM эквивалентен первому запуску ОС на железе.
Во время первого запуска будет необходимо установить язык, часовой пояс, указать логин+пароль для ОС.
Рекомендованная для использования версия ОС - "Minimal Version" без предзагрузки пакетов.

Важно дождаться переноса всех необходимых файлов из загрузочного образа, не нажимая кнопки SKIP.

7. Инициализация пакетного менеджера на виртуальной машины.

При первом запуске после загрузки системы необходимо открыть терминал (`Ctrl+Alt+T`) и выполнить команды:
```shell
sudo apt update
sudo apt upgrade
```
Эти команды произведут обновление всех пакетов на машине.
После завершения работы последней команды необходимо выключить виртуальную машину.

Если ОС жалуется, что вы не sudo-юзер, то нужно войти в сетему как root-пользователь с помощью команды:
```shell
su -
```

После перезапуска рекомендуется зайти в пункт меню Ubuntu под названием "Display" и установить комфортное для работы разрешение экрана.

8. Виртуальная машина готова к работе!

### Установка WSL

1. Установка WSL в Windows.

WSL можно скачать из магазина приложений Microsoft Store.
Достаточно установить приложения "Windows Subsystem for Linux" и "Ubuntu":

![images/wsl-1.png](images/wsl-1.png)

После установки обоих приложений следует открыть приложение "Ubuntu".
При этом откроется терминал, в котором следует пройти инициализацию и создать пользователя.

Файловая система Linux будет доступна из Explorer-а в Windows:

![images/wsl-2.png](images/wsl-2.png)

Для дальнейшей работы необходимо установить пакеты:
```
sudo apt update
sudo apt upgrade
sudo apt install build-essential gdb cmake
```

2. Настройка CLion.

Для того, чтобы подружить CLion и WSL, необходимо:
- Открыть окно `File -> Settings -> Build, Execution, Deployment -> Toolchains`.
- Нажать `+` и добавить WSL;
- Установить WSL как toolchain по умолчанию:

![images/wsl-3.png](images/wsl-3.png)

3. Настройка VS Code.

Для того, чтобы подружить VS Code и WSL, необходимо:
- Установить расширение WSL;
- После запуска VS Code нажать на зелёную кнопку в левом нижнем углу:

![images/wsl-4.png](images/wsl-4.png)

- Выбрать подключение к WSL:

![images/wsl-5.png](images/wsl-5.png)

## Памятка по основным командам консоли

Документация на любую команду консоли доступна по команде `man`.
Например, документация на команду `cat` высветится по команде `man cat`.

Полезные ссылки:
- [Туториал по базовой функциональности консоли Linux](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview).