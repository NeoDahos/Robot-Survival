#include <Engine\Collider\Collider.h>
#include <Engine\EngineCore.h>
#include <Engine\Collider\CollisionInfos.h>

namespace engine
{
	unsigned short Collider::s_instanceCount = 0;

	Collider::Collider(Object* const _parent, bool _isTrigger) : Component(_parent)
	{
		m_isTrigger = _isTrigger;
		m_isUnique = false;
		m_id = s_instanceCount;
		s_instanceCount++;

		/*m_onCollisionEnter = [this](const CollisionInfos& _collisionInfos) { printf("Collision Enter de %d avec %d !\n", m_id, _collisionInfos.m_other->m_id); };
		m_onTriggerEnter = [this](const CollisionInfos& _collisionInfos) { printf("Trigger Enter de %d avec %d !\n", m_id, _collisionInfos.m_other->m_id); };

		m_onCollisionStay = [this](const CollisionInfos& _collisionInfos) { printf("Collision de %d avec %d !\n", m_id, _collisionInfos.m_other->m_id); };
		m_onTriggerStay = [this](const CollisionInfos& _collisionInfos) { printf("Trigger de %d avec %d !\n", m_id, _collisionInfos.m_other->m_id); };

		m_onCollisionExit = [this](const CollisionInfos& _collisionInfos) { printf("Collision Exit de %d avec %d !\n", m_id, _collisionInfos.m_other->m_id); };
		m_onTriggerExit		= [this](const CollisionInfos& _collisionInfos) { printf("Trigger Exit de %d avec %d !\n", m_id, _collisionInfos.m_other->m_id); };*/

		m_onCollisionEnter = [](const CollisionInfos& _collisionInfos) { };
		m_onTriggerEnter = [](const CollisionInfos& _collisionInfos) { };

		m_onCollisionStay = [](const CollisionInfos& _collisionInfos) { };
		m_onTriggerStay = [](const CollisionInfos& _collisionInfos) { };

		m_onCollisionExit = [](const CollisionInfos& _collisionInfos) { };
		m_onTriggerExit = [](const CollisionInfos& _collisionInfos) { };

		ColliderMng.AddCollider(this);
	}

	Collider::Collider(const Collider& _other) : Collider(_other.m_parent, _other.m_isTrigger)
	{
		m_type = _other.m_type;
	}

	unsigned short Collider::GetId() const
	{
		return m_id;
	}

	Collider::ColliderType Collider::GetColliderType() const
	{
		return m_type;
	}

	auto Collider::FindCollider(unsigned short _id)
	{
		auto it = m_collidingIds.begin();
		auto itEnd = m_collidingIds.end();

		while (it != itEnd && (*it) != _id)
			++it;

		return it;
	}

	void Collider::ManageCollision(Collider* const _other, bool _isColliding)
	{
		CollisionInfos collisionInfos;
		collisionInfos.m_other = _other;

		CollisionInfos collisionInfosOther;
		collisionInfosOther.m_other = this;

		auto itSearch = FindCollider(_other->m_id);
		auto itEnd = m_collidingIds.end();

		if (_isColliding)
		{
			if (itSearch == itEnd)
			{
				m_collidingIds.push_back(_other->m_id);
				_other->m_collidingIds.push_back(m_id);

				if (m_isTrigger)
				{
					m_onTriggerEnter(collisionInfos);
					_other->m_onTriggerEnter(collisionInfosOther);
				}
				else
				{
					m_onCollisionEnter(collisionInfos);
					_other->m_onCollisionEnter(collisionInfosOther);
				}
			}
			else
			{
				if (m_isTrigger)
				{
					m_onTriggerStay(collisionInfos);
					_other->m_onTriggerStay(collisionInfosOther);
				}
				else
				{
					m_onCollisionStay(collisionInfos);
					_other->m_onCollisionStay(collisionInfosOther);
				}
			}
		}
		else if (!_isColliding && itSearch != itEnd)
		{
			m_collidingIds.erase(itSearch);
			_other->m_collidingIds.erase(_other->FindCollider(m_id));

			if (m_isTrigger)
			{
				m_onTriggerExit(collisionInfos);
				_other->m_onTriggerExit(collisionInfosOther);
			}
			else
			{
				m_onCollisionExit(collisionInfos);
				_other->m_onCollisionExit(collisionInfosOther);
			}
		}
	}
}