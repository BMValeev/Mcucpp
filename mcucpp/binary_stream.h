//*****************************************************************************
		using Source::Read;
		using Source::Write;

		static inline uint32_t ReadU32Le();
		static inline uint16_t ReadU16Be();
		static inline uint16_t ReadU16Le();

		static inline void WriteU32Be(uint32_t value);
		static inline void WriteU32Le(uint32_t value);
		static inline void WriteU16Be(uint16_t value);
		static inline void WriteU16Le(uint16_t value);

		/// Reads and discards specified number of bytes
		/// Returns last byte read
		static inline uint8_t Ignore(size_t bytes);

		/// Reads and discards specified number of bytes or until 'delim' byte is found
		/// Returns last byte read
		static inline uint8_t Ignore(size_t bytes, uint8_t delim);

		/// Reads and discards specified number of bytes while read byte is eq to 'value'
		/// Returns last byte read
		static inline uint8_t IgnoreWhile(size_t bytes, uint8_t value);



	template<class Source>

	template<class Source>

	template<class Source>

	template<class Source>
	void BinaryStream<Source>::WriteU32Be(uint32_t value)
	{
		Source::Write(uint8_t(value >> 24));
		Source::Write(uint8_t(value >> 16));
		Source::Write(uint8_t(value >> 8));
		Source::Write(uint8_t(value));
	}

	template<class Source>
	void BinaryStream<Source>::WriteU32Le(uint32_t value)
	{
		Source::Write(uint8_t(value));
		Source::Write(uint8_t(value >> 8));
		Source::Write(uint8_t(value >> 16));
		Source::Write(uint8_t(value >> 24));
	}

	template<class Source>
	void BinaryStream<Source>::WriteU16Be(uint16_t value)
	{
		Source::Write(uint8_t(value >> 8));
		Source::Write(uint8_t(value));
	}

	template<class Source>
	void BinaryStream<Source>::WriteU16Le(uint16_t value)
	{
		Source::Write(uint8_t(value));
		Source::Write(uint8_t(value >> 8));
	}

	template<class Source>
	uint8_t BinaryStream<Source>::Ignore(size_t bytes)
	{
		uint8_t value;
		for(size_t i = 0; i < bytes; ++i)
		return value;
	}

	template<class Source>
	uint8_t BinaryStream<Source>::Ignore(size_t bytes, uint8_t delim)
	{
		uint8_t value;
		for(size_t i = 0; i < bytes; ++i)
			if(value == delim)
				break;
		return value;
	}

	template<class Source>
	uint8_t BinaryStream<Source>::IgnoreWhile(size_t bytes, uint8_t expected)
	{
		uint8_t value;
		for(size_t i = 0; i < bytes; ++i)
			if(value != expected)
				break;
		return value;
	}