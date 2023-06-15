#pragma once
class Player
{
	public:
		int getVida() {
			return vida;
		}

		void quitarVida(int _vida) {
			vida = (vida - _vida) <= 0 ? 0 : (vida - _vida);
			muerte = (vida - _vida) <= 0 ? true : false;
		}

		void masVida(int _vida) {
			vida = (vida + _vida) >= 100 ? 100 : (vida + _vida);
		}

		void setVida(int _vida) {
			vida = _vida;
		}

		bool estaMuerto() {
			return muerte;
		}
	private:
		int vida = 100;
		bool muerte = false;
		bool colision = false;
};

