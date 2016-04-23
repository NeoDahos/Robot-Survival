#ifndef ANIMATION_H
#define ANIMATION_H
#include <Engine\Export.h>

#include <SFML\Graphics\Sprite.hpp>

namespace engine
{
	class ENGINE_API Animation : public sf::Sprite
	{
	public:
		Animation(const sf::Texture& _texture, int _rowCount, int _columnCount, int _frameCount, float _frameTime);
		~Animation();

		void SetPlaySpeed(float _speed);

		void Update(float _deltaTime);

		void Play();
		void Pause();
		void Stop();

	protected:
		sf::IntRect m_frameRect;

		float m_speed = 1.0f;
		float m_frameTime;
		float m_actualFrameTime = 0.0f;

		int m_rowCount = 1;
		int m_columnCount = 1;
		int m_frameCount = 1;
		int m_frameIndex = 0;

		bool m_isPlaying = true;
	};
}

#endif // ANIMATION_H