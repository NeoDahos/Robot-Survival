#ifndef ANIMATION_SHEET_H
#define ANIMATION_SHEET_H
#include <Engine\Export.h>

#include <SFML\Graphics\Sprite.hpp>
#include <vector>

namespace engine
{
	class ENGINE_API AnimationSheet : public sf::Sprite
	{
	public:
		struct AnimationInfos
		{
			sf::IntRect animRect;
			sf::Vector2u frameSize;

			float frameDuration = 0.f;
			float actualFrameTime = 0.f;

			unsigned short rowCount = 1;
			unsigned short columnCount = 1;
			unsigned short frameCount = 1;
			unsigned short frameIndex = 0;
		};

	public:
		AnimationSheet();
		~AnimationSheet();

		void SetPlaySpeed(float _speed);

		void AddAnimation(const AnimationInfos& _animation);

		void Init(const sf::Texture& _texture, bool _useGlobalTimer = true);
		void Update(float _deltaTime);

		void Play();
		void Play(unsigned short _animationIndex);
		void Pause();
		void Stop();

	protected:
		std::vector<AnimationInfos> m_animations;
		sf::IntRect m_frameRect;

		float m_speed = 1.0f;
		float m_globalFrameTime = 0.f;

		unsigned short m_animationIndex = 0;
		unsigned short m_globalFrameIndex = 0;

		bool m_isPlaying = true;
		bool m_useGlobalTimer = true;
	};
}

#endif // ANIMATION_SHEET_H