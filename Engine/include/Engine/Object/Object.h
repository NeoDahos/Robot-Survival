#ifndef OBJECT_H
#define OBJECT_H
#include <Engine\Export.h>

#include <SFML\System\String.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <list>

namespace sf
{
	class RenderTarget;
}

namespace engine
{
	class CollisionInfos;
	class Component;
	class Transform;

	class ENGINE_API Object
	{
	public:
		Object();
		Object(const Object& _other);
		virtual ~Object();

		template<typename T>
		T* const GetComponent() const;

		sf::Vector2f GetPosition() const;
		unsigned short GetId() const;

		void Move(const sf::Vector2f& _moveVector);

		virtual void Update(float _deltaTime);
		virtual void Draw(sf::RenderTarget& _target, const sf::RenderStates& _states = sf::RenderStates::Default);

		virtual void OnCollisionEnter(const CollisionInfos& _collisionInfos);
		virtual void OnCollisionStay(const CollisionInfos& _collisionInfos);
		virtual void OnCollisionExit(const CollisionInfos& _collisionInfos);
		virtual void OnTriggerEnter(const CollisionInfos& _collisionInfos);
		virtual void OnTriggerStay(const CollisionInfos& _collisionInfos);
		virtual void OnTriggerExit(const CollisionInfos& _collisionInfos);

		sf::String m_tag;

	public:
		static unsigned short s_instanceCount;

	protected:
		std::list<Component*> m_components;
		Transform* m_transform;
		unsigned short m_id;
	};
	
	template<typename T>
	T* const Object::GetComponent() const
	{
		auto it = m_components.begin();
		auto itEnd = m_components.end();
		T* component = nullptr;

		while ((component = dynamic_cast<T*>(*it)) == nullptr && it != itEnd)
			++it;

		return component;
	}
}

#endif // OBJECT_H