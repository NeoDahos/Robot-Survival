#include <Engine\Manager\ColliderManager.h>

#include <Engine\Collider\Collider.h>
#include <Engine\Collider\CircleCollider.h>

namespace engine
{
	ColliderManager::ColliderManager()
	{
	}

	ColliderManager::~ColliderManager()
	{
		m_colliders.clear();
	}

	void ColliderManager::AddCollider(Collider* const _collider)
	{
		m_colliders.push_back(_collider);
	}

	void ColliderManager::EraseCollider(Collider* const _collider)
	{
		auto it = m_colliders.begin();
		auto itEnd = m_colliders.end();

		while (it != itEnd && (*it) != _collider)
			++it;

		if (it != m_colliders.end())
			m_colliders.erase(it);
	}

	void ColliderManager::ComputeCollisions()
	{
		auto it1 = m_colliders.begin();
		auto it2 = m_colliders.begin();
		auto itEnd = m_colliders.end();

		for (it1; it1 != itEnd; ++it1)
		{
			for (it2 = std::next(it1); it2 != itEnd; ++it2)
			{
				if ((*it2)->GetType() == Collider::ColliderType::Circle)
					(*it1)->TestCollision(static_cast<CircleCollider*>(*it2));
			}
		}
	}
}