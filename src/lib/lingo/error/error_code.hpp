#ifndef H_LINGO_ERROR_ERROR_CODE
#define H_LINGO_ERROR_ERROR_CODE

namespace lingo
{
	namespace error
	{
		enum class error_code
		{
			success,

			buffer_too_small,
			invalid_point,
			invalid_unit,

			no_mapping,
		};
	}
}

#endif