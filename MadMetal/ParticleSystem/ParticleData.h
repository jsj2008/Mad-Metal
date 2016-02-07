#include <memory>
#include "..\Libraries\glm\vec4.hpp"
#include "..\Libraries\glm\vec3.hpp"

#ifndef _PARTICLEDATA_H
#define _PARTICLEDATA_H
class ParticleData
{
public:
	std::unique_ptr<glm::vec4[]> m_pos;
	std::unique_ptr<glm::vec3[]> m_norm;
	std::unique_ptr<glm::vec3[]> m_col;
	std::unique_ptr<glm::vec3[]> m_startCol;
	std::unique_ptr<glm::vec3[]> m_endCol;
	std::unique_ptr<glm::vec4[]> m_vel;
	std::unique_ptr<glm::vec4[]> m_acc;
	std::unique_ptr<float[]> m_time;
	std::unique_ptr<bool[]> m_alive;

	size_t m_count{ 0 };
	size_t m_countAlive{ 0 };

public:
	explicit ParticleData(size_t maxCount) { generate(maxCount); }
	~ParticleData() {}

	ParticleData(const ParticleData &) = delete;
	ParticleData &operator = (const ParticleData &) = delete;

	void generate(size_t maxSize);
	void kill(size_t id);
	void wake(size_t id);
	void swapData(size_t a, size_t b);
};

#endif /*_PARTICLEDATA_H*/