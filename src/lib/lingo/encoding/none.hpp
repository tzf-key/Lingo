#ifndef H_LINGO_ENCODING_NONE
#define H_LINGO_ENCODING_NONE

#include <lingo/platform/constexpr.hpp>

#include <lingo/encoding/endian.hpp>
#include <lingo/encoding/result.hpp>

namespace lingo
{
	namespace encoding
	{
		template <typename Unit, typename Point>
		struct none
		{
			using unit_type = Unit;
			using point_type = Point;

			using size_type = std::size_t;
			using difference_type = std::ptrdiff_t;

			static LINGO_CONSTEXPR11 size_type max_units = 1;

			static LINGO_CONSTEXPR14 encode_result encode_point(point_type point, unit_type* buffer, size_type buffer_size) noexcept
			{
				if (buffer_size == 0)
				{
					return { {}, error::error_code::buffer_too_small };
				}

				buffer[0] = static_cast<unit_type>(point);

				return { 1, error::error_code::success };
			}

			static LINGO_CONSTEXPR14 decode_result<point_type> decode_point(const unit_type* buffer, size_type buffer_size) noexcept
			{
				if (buffer_size == 0)
				{
					return { {}, 0, error::error_code::buffer_too_small };
				}

				return { static_cast<point_type>(buffer[0]), 1, error::error_code::success };
			}
		};

		#if LINGO_ARCHITECTURE_ENDIANNESS == LINGO_ARCHITECTURE_LITTLE_ENDIAN
		template <typename Unit, typename Point>
		using none_le = none<Unit, Point>;
		template <typename Unit, typename Point>
		using none_be = swap_endian<none<Unit, Point>>;
		#else
		template <typename Unit, typename Point>
		using none_le = swap_endian<none<Unit, Point>>;
		template <typename Unit, typename Point>
		using none_be = none<Unit, Point>;
		#endif
	}
}

#endif