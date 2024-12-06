# Игра "Морской бой"

Добро пожаловать в игру "Морской бой"! Это простая консольная игра, реализованная на C#. Цель игры — угадать координаты скрытых кораблей на сетке. Игроки по очереди пытаются угадать координаты, и игра предоставляет обратную связь о том, попали ли они в цель или нет.

## Особенности

- **Случайное размещение кораблей**: Корабли случайным образом размещаются на сетке заданных пользователем размеров.
- **Ввод от пользователя**: Игроки могут вводить свои предположения о местоположении кораблей.
- **Обратная связь "попадание" или "промах"**: Игра сообщает, попал ли игрок в корабль или нет.
- **Условие выигрыша**: Игра продолжается до тех пор, пока все корабли не будут успешно обнаружены.

## Начало работы

### Предварительные требования

Чтобы запустить эту игру, вам нужно:

- Установленный [SDK .NET](https://dotnet.microsoft.com/download) на вашем компьютере.

### Установка

1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/kene33/ship-game.git
   cd ship-game
   ```

2. Откройте проект в вашем любимом IDE (например, Visual Studio, Visual Studio Code).

3. Соберите и запустите проект:
   
```bash
   dotnet run
   ```

### Как играть

1. Когда вас попросят, введите количество строк и столбцов для игровой сетки.
2. Угадайте координаты кораблей, введя значения X (строка) и Y (столбец).
3. Игра сообщит вам, попали ли вы в корабль или нет.
4. Продолжайте угадывать, пока все корабли не будут обнаружены.

### Пример игрового процесса

```
Введите количество строк: 5
Введите количество столбцов: 5
X Y- - - - - - - - - - - - - - - - 
0|false false false  false false 
1|true  true  false  false false 
2|false false false  true  false 
3|false false false  false false 
4|false true  false  false true 
   0     1     2     3     4 

• - - - - - - - - - - - - - - - - 
Введите координату X: 1
Введите координату Y: 0
Корабль был потоплен! | X1 Y0
...

Вы потопили все корабли.
```
## Обзор кода

Основные компоненты кода включают:

- **Основной метод**: Инициализирует игру, генерирует случайную сетку и обрабатывает ввод пользователя.
- **Метод ShowMap**: Отображает текущее состояние игрового поля.
- **Метод AllElementsEqual**: Проверяет, были ли обнаружены все корабли.

## Участие

Ваши предложения и улучшения приветствуются! Если у вас есть идеи по улучшению или новым функциям, не стесняйтесь открывать проблемы или отправлять запросы на внесение изменений.

---

Наслаждайтесь игрой "Морской бой"! Если у вас есть вопросы или отзывы, пожалуйста, не стесняйтесь обращаться.
