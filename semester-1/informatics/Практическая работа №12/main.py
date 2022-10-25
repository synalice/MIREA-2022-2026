import keyboard
import numpy as np

"""Константы программы"""
SMALLEST_MATRIX_SIZE = 2  # минимальный допустимый размер матрицы
BIGGEST_MATRIX_SIZE = 5  # максимальный допустимый размер матрицы
SMALLEST_MATRIX_ELEMENT = 1  # минимальный допустимый размер элементов в матрице
BIGGEST_MATRIX_ELEMENT = 100  # максимальный допустимый размер элементов в матрице


def unknown_command():
	"""
	Функция unknown_command выводит список доступных команд, если пользователь ошибся во вводе.
	"""
	print("Неизвестная команда. Вот список того, что я умею")
	print("------------------------------------------------")
	print("rand - Создать квадратную матрицу c случайными числами")
	print("hand - Создать квадратную матрицу и заполнить вручную")
	print("exit   - Закрыть программу")


def print_help():
	"""
	Функция print_help выводит список доступных команд, если хочет посмотреть меню.
	"""
	print("Вот список того, что я умею")
	print("------------------------------------------------")
	print("help - Показать список доступных команд")
	print("rand - Создать квадратную матрицу c случайными числами")
	print("hand - Создать квадратную матрицу и заполнить вручную")
	print("exit - Закрыть программу")


def input_matrix_size():
	"""
	Функция input_matrix_size просит пользователя ввести размер матрицы и обрабатывает ошибки при вводе.
	"""
	print(
		f"Введите размер квадратной матрицы MxM, где M является целым числом"
		f"из диапазона [{SMALLEST_MATRIX_SIZE}, {BIGGEST_MATRIX_SIZE}]"
	)
	print("(для выхода из ввода размера напишите \"exit\")")
	matrix_size = None
	while True:
		try:
			matrix_size = input("[размер]>>> ")
			match matrix_size:
				case "help":
					print_help()
				case "exit":
					return "exit"
				case _:
					matrix_size = int(matrix_size)
			if SMALLEST_MATRIX_SIZE <= matrix_size <= BIGGEST_MATRIX_SIZE:
				break
			else:
				print(
					f"ОШИБКА: Размер матрицы должен быть числом из диапазона [{SMALLEST_MATRIX_SIZE}, {BIGGEST_MATRIX_SIZE}]"
				)
				continue
		except ValueError:
			print(
				f"ОШИБКА: Размер матрицы должен быть числом из диапазона [{SMALLEST_MATRIX_SIZE}, {BIGGEST_MATRIX_SIZE}]"
			)
			continue
	return matrix_size


def validate_inputted_row(inputted_row, matrix_size):
	"""
	Функция validate_inputted_row проверяет, являются введённые пользователем в строке матрицы элементы допустимыми.
	"""
	try:
		validated_row = list(map(int, inputted_row))
		if len(validated_row) != matrix_size:
			print(f"ОШИБКА: В строке должно быть {matrix_size} элементов")
			return False
		for i in validated_row:
			if i > BIGGEST_MATRIX_ELEMENT or i < SMALLEST_MATRIX_ELEMENT:
				print(
					f"ОШИБКА: Все элементы матрицы должны быть целыми числами "
					f"в диапазоне [{SMALLEST_MATRIX_ELEMENT}, {BIGGEST_MATRIX_ELEMENT}]"
				)
				return
	except ValueError:
		print(
			f"ОШИБКА: Все элементы матрицы должны быть целыми числами"
			f"в диапазоне [{SMALLEST_MATRIX_ELEMENT}, {BIGGEST_MATRIX_ELEMENT}]"
		)
		return False

	return validated_row


def hand_m():
	"""
	Функция hand_m обрабатывает ввод матрицы в ручном режиме.
	"""
	matrix_size = input_matrix_size()
	if matrix_size == "exit":
		return
	print(
		f"Ведите через пробел элементы матрицы - числа в диапазоне "
		f"[{SMALLEST_MATRIX_ELEMENT}, {BIGGEST_MATRIX_ELEMENT}]: "
	)
	while True:
		print("--------начало--------")
		hand_filled_matrix = input_row_by_row(matrix_size)
		if not hand_filled_matrix:
			continue
		print("--------конец---------")
		break

	# Преобразуем вложенный массив в более удобный массив библиотеки numpy
	hand_filled_matrix = np.array(hand_filled_matrix)

	print_original_matrix_and_1d_array(hand_filled_matrix)


def input_row_by_row(matrix_size):
	"""
	Функция inputted_row обрабатывает ввод пользователем строк матрицы.
	"""
	hand_filled_matrix = []
	for row in range(matrix_size):
		inputted_row = input("").split()
		validated_row = validate_inputted_row(inputted_row, matrix_size)
		if not validated_row:
			return False
		else:
			hand_filled_matrix.append(validated_row)
	return hand_filled_matrix


def rand_m():
	"""
	Функция rand_m отвечает за генерацию матрицы, заполненной случайными числами
	"""
	matrix_size = input_matrix_size()
	if matrix_size == "exit":
		return
	random_matrix = (np.random.randint(SMALLEST_MATRIX_ELEMENT, BIGGEST_MATRIX_ELEMENT+1, (matrix_size, matrix_size)))
	print_original_matrix_and_1d_array(random_matrix)


def print_original_matrix_and_1d_array(matrix: np.ndarray):
	"""
	Функция print_original_matrix_and_1d_array выводит в консоль сначала исходную матрицу, а затем матрицу,
	преобразованную в одномерный массив, отсортированный сначала по возрастанию четных элементов, а затем по убыванию
	нечётных элементов.
	"""
	print()
	print("Ваша матрица:")
	print(matrix)
	matrix_in_1d = list(matrix.flatten())
	even_elems = sorted([num for num in matrix_in_1d if num % 2 == 0])
	odd_elems = sorted([num for num in matrix_in_1d if num % 2 == 1], reverse=True)
	print()
	print("Матрица в виде одномерного массива:")
	print([*even_elems, *odd_elems])


def main():
	keyboard.block_key("ctrl")  # Блокируем клавишу ctrl

	print("Напишите \"help\", чтобы узнать, что я умею!")

	while True:
		user_input = input("\n[меню]>>> ")

		# Программа определяет, что ей делать, в зависимости от ввода пользователя
		match user_input:
			case "help":
				print_help()
			case "rand":
				rand_m()
			case "hand":
				hand_m()
			case "exit":
				exit()
			case _:
				unknown_command()


if __name__ == '__main__':
	try:
		main()
	except KeyboardInterrupt:  # Дополнительная защита от Ctrl+C
		pass
