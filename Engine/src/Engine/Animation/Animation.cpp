#include <Engine\Animation\Animation.h>

namespace engine
{
	Animation::Animation(const sf::Texture& _texture, int _rowCount, int _columnCount, int _frameCount, float _frameTime)
		: m_rowCount(_rowCount), m_columnCount(_columnCount), m_frameCount(_frameCount), m_frameTime(_frameTime)
	{
		setTexture(_texture);

		m_frameRect = getTextureRect();
		m_frameRect.width /= m_columnCount;
		m_frameRect.height /= m_rowCount;

		setTextureRect(m_frameRect);
	}

	Animation::~Animation()
	{
	}

	void Animation::SetPlaySpeed(float _speed)
	{
		m_speed = _speed;
	}

	void Animation::Update(float _deltaTime)
	{
		if (m_isPlaying)
		{
			m_actualFrameTime += _deltaTime;

			if (m_actualFrameTime >= m_frameTime / m_speed)
			{
				m_frameIndex = (m_frameIndex + 1) % m_frameCount;

				m_actualFrameTime -= (m_frameTime / m_speed);
				m_frameRect.left = m_frameRect.width * (m_frameIndex % m_columnCount);
				m_frameRect.top = m_frameRect.height * (m_frameIndex / m_columnCount);
				setTextureRect(m_frameRect);
			}
		}
	}

	void Animation::Play()
	{
		m_isPlaying = true;
	}

	void Animation::Pause()
	{
		m_isPlaying = false;
	}

	void Animation::Stop()
	{
		m_isPlaying = false;
		m_actualFrameTime = 0.0f;
		m_frameIndex = 0;
	}
}