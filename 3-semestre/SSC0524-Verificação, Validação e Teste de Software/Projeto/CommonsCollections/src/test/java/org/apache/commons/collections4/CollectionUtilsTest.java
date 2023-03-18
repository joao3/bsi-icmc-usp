package org.apache.commons.collections4;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertInstanceOf;
import static org.junit.jupiter.api.Assertions.assertIterableEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNotSame;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertSame;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.Queue;
import java.util.Set;

import org.apache.commons.collections4.iterators.ArrayIterator;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

public class CollectionUtilsTest {

	private Iterable<Integer> iterableA = null;

	private Iterable<Long> iterableB = null;

	private Iterable<Integer> iterableC = null;

	private Iterable<Number> iterableA2 = null;

	private Iterable<Number> iterableB2 = null;

	@Test
	public void containsAll() {
		Collection<Object> list1 = new ArrayList<>();
		list1.add(5);
		list1.add(null);
		Collection<Object> list2 = new ArrayList<>();
		list2.add(6);
		list2.add(null);
		boolean containsAll = CollectionUtils.containsAll(list1, list2);

		assertEquals(containsAll, false);
	}

	@Test
	public void containsAll1() {
		Collection<Integer> list1 = new ArrayList<>();
		Collection<Integer> list2 = new ArrayList<>();
		boolean containsAll = CollectionUtils.containsAll(list1, list2);

		assertEquals(containsAll, true);
	}

	@Test
	public void intersection() {
		Collection<Integer> list1 = new ArrayList<>();
		list1.add(5);
		list1.add(6);
		Collection<Integer> list2 = new ArrayList<>();
		list2.add(6);
		list2.add(8);

		Collection<Integer> list3 = CollectionUtils.intersection(list1, list2);

		Collection<Integer> expected = new ArrayList<>();
		expected.add(6);

		assertIterableEquals(expected, list3);
	}

	@Test
	public void disjunction() {
		Collection<Integer> list1 = new ArrayList<>();
		list1.add(5);
		list1.add(6);
		Collection<Integer> list2 = new ArrayList<>();
		list2.add(6);
		list2.add(8);

		Collection<Integer> list3 = CollectionUtils.disjunction(list1, list2);

		Collection<Integer> expected = new ArrayList<>();
		expected.add(5);
		expected.add(8);

		assertIterableEquals(expected, list3);
	}

	@Test
	public void subtract() {
		Collection<Integer> list1 = new ArrayList<>();
		list1.add(5);
		list1.add(6);
		Collection<Integer> list2 = new ArrayList<>();
		list2.add(6);
		list2.add(8);

		Collection<Integer> list3 = CollectionUtils.subtract(list1, list2);

		Collection<Integer> expected = new ArrayList<>();
		expected.add(5);

		assertIterableEquals(expected, list3);
	}

	@Test
	public void emptyIfNull() {
		Collection<Object> collection = CollectionUtils.emptyIfNull(null);
		assertEquals(collection.isEmpty(), true);
	}

	@Test
	public void emptyIfNull2() {
		Collection<Integer> list1 = new ArrayList<>();
		list1.add(5);
		list1.add(6);

		Collection<Integer> collection = CollectionUtils.emptyIfNull(list1);
		assertEquals(collection.isEmpty(), false);
	}

	@Test
	public void containsAnyInCollection() {
		final Collection<String> empty = new ArrayList<>(0);
		final Collection<String> one = new ArrayList<>(1);
		one.add("1");
		final Collection<String> two = new ArrayList<>(1);
		two.add("2");
		final Collection<String> three = new ArrayList<>(1);
		three.add("3");
		final Collection<String> odds = new ArrayList<>(2);
		odds.add("1");
		odds.add("3");

		assertTrue( CollectionUtils.containsAny(one  , odds ));
		assertTrue( CollectionUtils.containsAny(odds , one  ));
		assertTrue( CollectionUtils.containsAny(three, odds ));
		assertTrue( CollectionUtils.containsAny(odds , three));
		assertTrue( CollectionUtils.containsAny(two  , two  ));
		assertTrue( CollectionUtils.containsAny(odds , odds ));
		assertTrue(!CollectionUtils.containsAny(two  , odds ));
		assertTrue(!CollectionUtils.containsAny(odds , two  ));
		assertTrue(!CollectionUtils.containsAny(one  , three));
		assertTrue(!CollectionUtils.containsAny(three, one  ));
		assertTrue(!CollectionUtils.containsAny(odds , empty));
		assertTrue(!CollectionUtils.containsAny(empty, odds ));
		assertTrue(!CollectionUtils.containsAny(empty, empty));
	}

	@Test
	public void containsAnyInArray() {
		final Collection<String> empty = new ArrayList<>(0);
		final String[] emptyArr = {};
		final Collection<String> one = new ArrayList<>(1);
		one.add("1");
		final String[] oneArr = { "1" };
		final Collection<String> two = new ArrayList<>(1);
		two.add("2");
		final String[] twoArr = { "2" };
		final Collection<String> three = new ArrayList<>(1);
		three.add("3");
		final String[] threeArr = { "3" };
		final Collection<String> odds = new ArrayList<>(2);
		odds.add("1");
		odds.add("3");
		final String[] oddsArr = { "1", "3" };

		assertTrue(  CollectionUtils.containsAny(one  , oddsArr ));
		assertTrue(  CollectionUtils.containsAny(odds , oneArr  ));
		assertTrue(  CollectionUtils.containsAny(three, oddsArr ));
		assertTrue(  CollectionUtils.containsAny(odds , threeArr));
		assertTrue(  CollectionUtils.containsAny(two  , twoArr  ));
		assertTrue(  CollectionUtils.containsAny(odds , oddsArr ));
		assertTrue( !CollectionUtils.containsAny(two  , oddsArr ));
		assertTrue( !CollectionUtils.containsAny(odds , twoArr  ));
		assertTrue( !CollectionUtils.containsAny(one  , threeArr));
		assertTrue( !CollectionUtils.containsAny(three, oneArr  ));
		assertTrue( !CollectionUtils.containsAny(odds , emptyArr));
		assertTrue( !CollectionUtils.containsAny(empty, oddsArr ));
		assertTrue( !CollectionUtils.containsAny(empty, emptyArr));
	}

	@Test
	public void containsAll2() {
		final Collection<String> empty = new ArrayList<>(0);
		final Collection<String> one = new ArrayList<>(1);
		one.add("1");
		final Collection<String> two = new ArrayList<>(1);
		two.add("2");
		final Collection<String> three = new ArrayList<>(1);
		three.add("3");
		final Collection<String> odds = new ArrayList<>(2);
		odds.add("1");
		odds.add("3");
		final Collection<String> multiples = new ArrayList<>(3);
		multiples.add("1");
		multiples.add("3");
		multiples.add("1");

		assertTrue(!CollectionUtils.containsAll(one  , odds     ));
		assertTrue( CollectionUtils.containsAll(odds , one      ));
		assertTrue(!CollectionUtils.containsAll(three, odds     ));
		assertTrue( CollectionUtils.containsAll(odds , three    ));
		assertTrue( CollectionUtils.containsAll(two  , two      ));
		assertTrue( CollectionUtils.containsAll(odds , odds     ));
		assertTrue(!CollectionUtils.containsAll(two  , odds     ));
		assertTrue(!CollectionUtils.containsAll(odds , two      ));
		assertTrue(!CollectionUtils.containsAll(one  , three    ));
		assertTrue(!CollectionUtils.containsAll(three, one      ));
		assertTrue( CollectionUtils.containsAll(odds , empty    ));
		assertTrue(!CollectionUtils.containsAll(empty, odds     ));
		assertTrue( CollectionUtils.containsAll(empty, empty    ));
		assertTrue( CollectionUtils.containsAll(odds , multiples));
		assertTrue( CollectionUtils.containsAll(odds , odds     ));
	}

	@Test
	public void isSubCollection() {
		final Collection<String> one = new ArrayList<>();
		one.add("1");
		one.add("2");
		one.add("3");
		one.add("4");
		one.add("5");

		assertTrue( CollectionUtils.isSubCollection(one, one));
	}
	
	@Test
	public void isSubCollection1() {
		final Collection<String> one = new ArrayList<>();
		one.add("1");
		one.add("2");
		one.add("3");
		one.add("4");
		one.add("5");
		
		final Collection<String> two = new ArrayList<>();
		one.add("1");
		one.add("7");
		one.add("3");
		
		assertEquals(CollectionUtils.isSubCollection(one, two),false);
	}
	@Test
	public void isProperSubCollection() {
		final Collection<String> one = new ArrayList<>();
		one.add("1");
		one.add("2");
		one.add("3");
		one.add("4");
		one.add("5");
		
		final Collection<String> two = new ArrayList<>();
		two.add("1");
		two.add("2");
		two.add("3");
		
		assertEquals(CollectionUtils.isProperSubCollection(one, two),false);
		assertEquals(CollectionUtils.isProperSubCollection(two, one),true);

	}

	@Test
	public void testIsEqualCollectionToSelf() {
		final Collection<String> one = new ArrayList<>();
		final Collection<String> two = new ArrayList<>();

		assertTrue(CollectionUtils.isEqualCollection(one, one));
		assertTrue(CollectionUtils.isEqualCollection(two, two));
	}

	@Test
	public void testIsEqualCollection() {
		final Collection<String> one = new ArrayList<>();
		final Collection<String> two = new ArrayList<>();
		assertTrue(CollectionUtils.isEqualCollection(one, two));
		assertTrue(CollectionUtils.isEqualCollection(two, one));
	}

	@Test
	public void testIsEqualCollectionReturnsFalse() {
		final Collection<Integer> one = new ArrayList<>();
		one.add(1);
		one.add(2);

		final List<Integer> b = new ArrayList<>(one);
		// remove an extra '2', and add a 5. This will increase the size of the
		// cardinality
		b.remove(1);
		b.add(5);
		assertFalse(CollectionUtils.isEqualCollection(one, b));
		assertFalse(CollectionUtils.isEqualCollection(b, one));
	}

	@Test
	public void testIsEqualCollection3() {
		final Collection<String> a = new ArrayList<>();
		final Collection<String> b = new ArrayList<>();
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
		a.add("1");
		assertTrue(!CollectionUtils.isEqualCollection(a, b));
		assertTrue(!CollectionUtils.isEqualCollection(b, a));
		b.add("1");
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
		a.add("2");
		assertTrue(!CollectionUtils.isEqualCollection(a, b));
		assertTrue(!CollectionUtils.isEqualCollection(b, a));
		b.add("2");
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
		a.add("1");
		assertTrue(!CollectionUtils.isEqualCollection(a, b));
		assertTrue(!CollectionUtils.isEqualCollection(b, a));
		b.add("1");
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
	}

	Transformer<String, Integer> TRANSFORM_TO_INTEGER = new Transformer<String, Integer>() {
		@Override
		public Integer transform(final String input) {
			return Integer.getInteger(input);
		}
	};

	@Test
	public void testIsEqualCollectionEquator() {
		final Collection<Integer> a = new ArrayList<>();
		final Collection<String> b = new ArrayList<>();
		b.add("1");
		b.add("2");
		b.add("3");
		b.add("4");
		b.add("5");
		b.add("6");
		b.add("7");
		b.add("8");

		final Collection<Integer> collB = CollectionUtils.collect(b, TRANSFORM_TO_INTEGER);
		// odd / even equator
		final Equator<Integer> e = new Equator<Integer>() {
			@Override
			public boolean equate(final Integer o1, final Integer o2) {
				if (o1.intValue() % 2 == 0 ^ o2.intValue() % 2 == 0) {
					return false;
				}
				return true;
			}

			@Override
			public int hash(final Integer o) {
				return o.intValue() % 2 == 0 ? Integer.valueOf(0).hashCode() : Integer.valueOf(1).hashCode();
			}
		};

		assertTrue(CollectionUtils.isEqualCollection(a, a, e));
		assertTrue(!CollectionUtils.isEqualCollection(a, collB, e));
		assertTrue(!CollectionUtils.isEqualCollection(collB, a, e));
	}
	@Test
	public void testIsEqualCollection2() {
		final Collection<String> a = new ArrayList<>();
		final Collection<String> b = new ArrayList<>();
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
		a.add("1");
		assertTrue(!CollectionUtils.isEqualCollection(a, b));
		assertTrue(!CollectionUtils.isEqualCollection(b, a));
		b.add("1");
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
		a.add("2");
		assertTrue(!CollectionUtils.isEqualCollection(a, b));
		assertTrue(!CollectionUtils.isEqualCollection(b, a));
		b.add("2");
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
		a.add("1");
		assertTrue(!CollectionUtils.isEqualCollection(a, b));
		assertTrue(!CollectionUtils.isEqualCollection(b, a));
		b.add("1");
		assertTrue(CollectionUtils.isEqualCollection(a, b));
		assertTrue(CollectionUtils.isEqualCollection(b, a));
	}
	
	@Test
	public void cardinality() {
		Integer luckyNumber = 7;
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);
		a.add(6);
		a.add(7);
		a.add(7);
		a.add(7);
		assertEquals(3, CollectionUtils.cardinality(luckyNumber, a));
	}

	@Test
	public void find() {
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n < 2;
		};

		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);
		a.add(6);
		a.add(7);
		a.add(7);
		a.add(7);

		assertEquals(1, CollectionUtils.find(a, predicate));
		assertEquals(null, CollectionUtils.find(a, null));
	}

	@Test
	public void forAllDo() {
		Closure clearCollection = new Closure() {
			@Override
			public void execute(final Object input) {
				((Collection) input).clear();
			}
		};
		
		final Collection<Collection<Integer>> col = new ArrayList<>();
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		final Collection<Integer> b = new ArrayList<>();
		b.add(2);
		b.add(4);

		col.add(a);
		col.add(b);
		Closure<Collection<Integer>> resultClosure = CollectionUtils.forAllDo(col, clearCollection);
		assertSame(clearCollection, resultClosure);
		assertTrue(a.isEmpty() && b.isEmpty());
	}
	
	@Test
	public void forAllDo1() {
		Closure clearCollection = new Closure() {
			@Override
			public void execute(final Object input) {
				((Collection) input).clear();
			}
		};
		
		final Collection<Collection<Integer>> col = new ArrayList<>();
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		final Collection<Integer> b = new ArrayList<>();
		b.add(2);
		b.add(4);

		col.add(a);
		col.add(b);
		Closure<Collection<Integer>> resultClosure = CollectionUtils.forAllDo(col.iterator(), clearCollection);
		assertSame(clearCollection, resultClosure);
		assertTrue(a.isEmpty() && b.isEmpty());
	}

	@Test
	public void forAllButLastDo() {
		Closure clearCollection = new Closure() {
			@Override
			public void execute(final Object input) {
				((Collection) input).clear();
			}
		};
		
		final Collection<Collection<Integer>> col = new ArrayList<>();
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		final Collection<Integer> b = new ArrayList<>();
		b.add(2);
		b.add(4);

		col.add(a);
		col.add(b);
		
		Collection<Integer> resultCollection = CollectionUtils.forAllButLastDo(col, clearCollection);
		
		assertTrue(a.isEmpty());
		assertTrue(!b.isEmpty());
		
		Collection<Integer> resultCollection2= CollectionUtils.forAllButLastDo(col, null);
		Collection<Integer> resultCollection3 = CollectionUtils.forAllButLastDo(col.iterator(), null);
		
		assertEquals(null,resultCollection2);
		assertEquals(null,resultCollection3);
	}
	
	@Test
	public void filter() {
		
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n < 10;
		};
		
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);

		assertTrue(!CollectionUtils.filter(null, predicate));
		assertTrue(!CollectionUtils.filter(a, null));
		
		boolean result = CollectionUtils.filter(a, predicate);
		
		assertTrue(!result);
		
		a.add(12);
		
		assertTrue(CollectionUtils.filter(a, predicate));
	}
	

	
	@Test
	public void filterInverse() {
		
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n < 10;
		};
		
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);

		assertTrue(!CollectionUtils.filterInverse(null, predicate));
		assertTrue(!CollectionUtils.filterInverse(a, null));
		
		boolean result = CollectionUtils.filterInverse(a, predicate);
		
		assertTrue(result);
		
		a.add(12);
		
		assertTrue(!CollectionUtils.filterInverse(a, predicate));
	}	
	

	@Test
	public void transform() {		
		Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);
		
		CollectionUtils.transform(a, TransformerUtils.constantTransformer(7));
		
		// array list with only two elements
		Collection<Integer> b = new ArrayList<>();
		b.add(7);
		b.add(7);
		b.add(7);
		b.add(7);
		b.add(7);

		assertIterableEquals(b, a);
		
		final Set<Number> set = new HashSet<>();
		set.add(1L);
		set.add(2L);
		set.add(3L);
		CollectionUtils.transform(set, new Transformer<Object, Integer>() {
		    @Override
		    public Integer transform(final Object input) {
		        return 4;
		    }
		});
		assertEquals(1, set.size());
		assertEquals(4, set.iterator().next());
	}	
	
	@Test
	public void countMatches() {
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n < 10;
		};
		
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);

		assertEquals(CollectionUtils.countMatches(a, predicate), 5);
		assertEquals(CollectionUtils.countMatches(a, null), 0);

	}

	
	@Test
	public void exists() {
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n == 4;
		};
		
		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);

		assertEquals(CollectionUtils.exists(a, predicate), true);
		
		assertEquals(CollectionUtils.exists(a, null), false);
	}	
	@Test
	void get1() {
		HashMap<Integer, Integer> map = new HashMap<>();
		map.put(1, 3);
		assertEquals(Map.entry(1, 3), CollectionUtils.get(map, 0));
	}

	@Test
	void get2() {
		HashMap<Integer, Integer> map = new HashMap<>();
		assertThrows(IndexOutOfBoundsException.class, () -> {CollectionUtils.get(map, 4);});

	}

	@Test
	void get3() {
		Integer test = 4;
		Iterator it = new Iterator() {
			int n = 1, nMax = 2;
			@Override
			public boolean hasNext() {
				n++;
				return n - 1 < nMax;
			}

			@Override
			public Object next() {
				if (n == 2)
					return test;
				return null;
			}
		};
		assertEquals(test, CollectionUtils.get(it, 0));
	}

	@Test
	void get4() {
		int from = 1, to = 2;
		Iterable i = new Iterable() {
			@Override
			public Iterator iterator() {
				return new Iterator<Integer>() {
					int current = from;
					public boolean hasNext() { return current < to; }
					public Integer next() {
						if (!hasNext()) { throw new NoSuchElementException(); }
						return current++;
					}
					public void remove() { /*Optional; not implemented.*/ }
				};
			}
		};
		assertEquals(1, CollectionUtils.get(i, 0));
	}

	@Test
	void get5() {
		Object list = new ArrayList<>();
		assertThrows(IndexOutOfBoundsException.class, () -> {CollectionUtils.get(list, -1);});
	}

	@Test
	void get6() {
		Object map = new HashMap<>();
		((HashMap) map).put(1, 3);
		assertEquals(Map.entry(1, 3), CollectionUtils.get(map, 0));
	}

	@Test
	void get7() {
		Object array = new Integer[]{1};
		assertEquals(1, CollectionUtils.get(array, 0));
	}

	@Test
	void get8() {
		Integer test = 4;
		Object it = new Iterator() {
			int n = 1, nMax = 2;
			@Override
			public boolean hasNext() {
				n++;
				return n - 1 < nMax;
			}

			@Override
			public Object next() {
				if (n == 2)
					return test;
				return null;
			}
		};
		assertEquals(test, CollectionUtils.get(it, 0));
	}

	@Test
	void get9() {
		int from = 1, to = 2;
		Object i = new Iterable() {
			@Override
			public Iterator iterator() {
				return new Iterator<Integer>() {
					int current = from;
					public boolean hasNext() { return current < to; }
					public Integer next() {
						if (!hasNext()) { throw new NoSuchElementException(); }
						return current++;
					}
					public void remove() { /*Optional; not implemented.*/ }
				};
			}
		};
		assertEquals(1, CollectionUtils.get(i, 0));
	}

	@Test
	void get10() {
		Integer a = 4;
		Object en = new Enumeration() {
			int n = 0;
			@Override
			public boolean hasMoreElements() {
				if (n == 0)
					return true;
				return false;
			}

			@Override
			public Object nextElement() {
				if (n == 0) {
					n++;
					return a;
				}
				return null;
			}
		};

		assertEquals(a, CollectionUtils.get(en, 0));
	}

	@Test
	void get11() {
		assertThrows(IllegalArgumentException.class, () -> {CollectionUtils.get((Object) null, 0);});
	}

	@Test
	void get12() {
		assertEquals(1, CollectionUtils.get(new int[]{1}, 0));
	}

	@Test
	void addAll1() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5));
		Integer[] elements = new Integer[]{};
		assertFalse(CollectionUtils.addAll(list, elements));
	}

	@Test
	void addAll2() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5));
		Integer[] elements = new Integer[]{3, 1};
		assertTrue(CollectionUtils.addAll(list, elements));
		assertIterableEquals(new ArrayList<>(Arrays.asList(3, 5, 3, 1)), list);
	}

	@Test
	void addAll3() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5));
		Integer a = 4;
		Enumeration elements = new Enumeration() {
			int n = 0;
			@Override
			public boolean hasMoreElements() {
				if (n == 0)
					return true;
				return false;
			}

			@Override
			public Object nextElement() {
				if (n == 0) {
					n++;
					return a;
				}
				return null;
			}
		};
		assertTrue(CollectionUtils.addAll(list, elements));
		assertIterableEquals(new ArrayList<>(Arrays.asList(3, 5, 4)), list);
	}

	@Test
	void addAll4() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5));
		Enumeration elements = new Enumeration() {
			@Override
			public boolean hasMoreElements() {
				return false;
			}

			@Override
			public Object nextElement() {
				return null;
			}
		};
		assertFalse(CollectionUtils.addAll(list, elements));
		assertIterableEquals(new ArrayList<>(Arrays.asList(3, 5)), list);
	}

	@Test
	void addAll5() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 7));
		Iterator<Integer> add = new ArrayIterator<Integer>(new Integer[]{});
		assertFalse(CollectionUtils.addAll(list, add));
		assertIterableEquals(list, Arrays.asList(3, 7));
	}

	@Test
	void addAll6() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 7));
		Iterator<Integer> add = new ArrayIterator<Integer>(new Integer[]{4, 5});
		assertTrue(CollectionUtils.addAll(list, add));
		assertIterableEquals(list, Arrays.asList(3, 7, 4, 5));
	}

	@Test
	void addAll7() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 7));
		Iterable<Integer> add = new ArrayList<Integer>(Arrays.asList(new Integer[]{}));
		assertFalse(CollectionUtils.addAll(list, add));
		assertIterableEquals(list, Arrays.asList(3, 7));
	}

	@Test
	void addAll8() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 7));
		Iterable<Integer> add = new ArrayList<Integer>(Arrays.asList(new Integer[]{5, 4}));
		assertTrue(CollectionUtils.addAll(list, add));
		assertIterableEquals(list, Arrays.asList(3, 7, 5, 4));
	}

	@Test
	void addIgnoreNull1() {
		assertThrows(NullPointerException.class, () -> {CollectionUtils.addIgnoreNull(null, 4);});
	}

	@Test
	void addIgnoreNull2() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(2, 4));
		assertTrue(CollectionUtils.addIgnoreNull(list, 5));
	}

	@Test
	void addIgnoreNull3() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(2, 4));
		assertFalse(CollectionUtils.addIgnoreNull(list, null));
	}

	@Test
	void collect1() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list.iterator(), tr, output));
	}

	@Test
	void collect2() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list.iterator(), tr, output));
	}

	@Test
	void collect3() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list, tr, output));
	}

	@Test
	void collect4() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list, tr, output));
	}

	@Test
	void collect5() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list.iterator(), tr));
	}

	@Test
	void collect6() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list.iterator(), tr));
	}

	@Test
	void collect7() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list, tr));
	}

	@Test
	void collect8() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(3, 5, 7));
		ArrayList<Integer> output = new ArrayList<>();
		Transformer tr = new Transformer() {
			@Override
			public Object transform(Object input) {
				return  ((Integer) input)+1;
			}
		};
		assertIterableEquals(Arrays.asList(4, 6, 8), CollectionUtils.collect(list, tr));
	}

	@Test
	void collect9() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(5);
		assertIterableEquals(list, CollectionUtils.collect((Iterable) null, null, list));
	}

	@Test
	void selectRejected1(){
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(4, 15, 0, -3, 6, 20));
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		assertIterableEquals(Arrays.asList(4, 0, -3, 6), CollectionUtils.selectRejected(list, predicate));
	}

	@Test
	void selectRejected2(){
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(4, 15, 0, -3, 6, 20));
		ArrayList<Integer> out = new ArrayList<>(Arrays.asList(7));
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		assertIterableEquals(Arrays.asList(7, 4, 0, -3, 6), CollectionUtils.selectRejected(list, predicate, out));
	}

	@Test
	void select1(){
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(4, 15, 0, -3, 6, 20));
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		assertIterableEquals(Arrays.asList(15, 20), CollectionUtils.select(list, predicate));
	}

	@Test
	void select2(){
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(4, 15, 0, -3, 6, 20));
		ArrayList<Integer> out = new ArrayList<>(Arrays.asList(7));
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		assertIterableEquals(Arrays.asList(7, 15, 20), CollectionUtils.select(list, predicate, out));
	}

	@Test
	void select3(){
		ArrayList<Integer> out = new ArrayList<>(Arrays.asList(7));
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		assertIterableEquals(Arrays.asList(7), CollectionUtils.select(null, predicate, out));
	}

	@Test
	void select4() {
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(4, 15, 0, -3, 6, 20));
		ArrayList<Integer> out = new ArrayList<>(Arrays.asList(7));
		ArrayList<Integer> rejected = new ArrayList<>();
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		ArrayList<Integer> result = CollectionUtils.select(list, predicate, out, rejected);
		assertIterableEquals(Arrays.asList(7, 15, 20),  result);
		assertIterableEquals(Arrays.asList(4, 0, -3, 6), rejected);
	}

	@Test
	void select5() {
		ArrayList<Integer> out = new ArrayList<>(Arrays.asList(7));
		ArrayList<Integer> rejected = new ArrayList<>();
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};
		ArrayList<Integer> result = CollectionUtils.select(null, predicate, out, rejected);
		assertIterableEquals(Arrays.asList(7),  result);
	}

	@Test
	public void matchesAll1() {
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n < 10;
		};

		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(53);
		a.add(3);
		a.add(4);
		a.add(5);

		assertFalse(CollectionUtils.matchesAll(a, predicate));
	}

	@Test
	public void matchesAll2() {
		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n < 10;
		};

		final Collection<Integer> a = new ArrayList<>();
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);

		assertTrue(CollectionUtils.matchesAll(a, predicate));
	}

	@Test
	void sizeNull() {
		assertEquals(0, CollectionUtils.size(null));
	}

	@Test
	void sizeMap() {
		HashMap<Integer, Integer> map = new HashMap<>();
		map.put(3, 5);
		assertEquals(1, CollectionUtils.size(map));
	}

	@Test
	void sizeCollection() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(1);
		assertEquals(1, CollectionUtils.size(list));
	}

	@Test
	void sizeIterable() {
		int from = 1, to = 2;
		Iterable i = new Iterable() {
			@Override
			public Iterator iterator() {
				return new Iterator<Integer>() {
					int current = from;
					public boolean hasNext() { return current < to; }
					public Integer next() {
						if (!hasNext()) { throw new NoSuchElementException(); }
						return current++;
					}
					public void remove() { /*Optional; not implemented.*/ }
				};
			}
		};
		assertEquals(1, CollectionUtils.size(i));
	}

	@Test
	void sizeArray() {
		Integer[] array = {1};
		assertEquals(1, CollectionUtils.size(array));
	}

	@Test
	void sizeIterator() {
		Iterator it = new Iterator() {
			int n = 1, nMax = 2;
			@Override
			public boolean hasNext() {
				n++;
				return n - 1 < nMax;
			}

			@Override
			public Object next() {
				return null;
			}
		};
		assertEquals(1, CollectionUtils.size(it));
	}

	@Test
	void sizeEnumeration() {
		Enumeration en = new Enumeration() {
			int n = 1, nMax = 2;
			@Override
			public boolean hasMoreElements() {
				n++;
				return n - 1 < nMax;
			}

			@Override
			public Object nextElement() {
				return null;
			}
		};

		assertEquals(1, CollectionUtils.size(en));
	}

	@Test
	void size() {
		assertEquals(1, CollectionUtils.size(new int[]{1}));
	}

	@Test
	void sizeIsEmpty1() {
		assertFalse(CollectionUtils.sizeIsEmpty(new int[]{4}));
	}

	@Test
	void sizeIsEmpty2() {
		assertTrue(CollectionUtils.sizeIsEmpty(new int[]{}));
	}

	@Test
	void sizeIsEmptyNull() {
		assertTrue(CollectionUtils.sizeIsEmpty(null));
	}

	@Test
	void sizeIsEmptyCollection1() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(1);
		assertFalse(CollectionUtils.sizeIsEmpty(list));
	}

	@Test
	void sizeIsEmptyCollection2() {
		ArrayList<Integer> list = new ArrayList<>();
		assertTrue(CollectionUtils.sizeIsEmpty(list));
	}

	@Test
	void sizeIsEmptyIterable1() {
		int from = 1, to = 5;
		Iterable i = new Iterable() {
			@Override
			public Iterator iterator() {
				return new Iterator<Integer>() {
					int current = from;
					public boolean hasNext() { return current < to; }
					public Integer next() {
						if (!hasNext()) { throw new NoSuchElementException(); }
						return current++;
					}
					public void remove() { /*Optional; not implemented.*/ }
				};
			}
		};
		assertFalse(CollectionUtils.sizeIsEmpty(i));
	}

	@Test
	void sizeIsEmptyIterable2() {
		int from = 1, to = 1;
		Iterable i = new Iterable() {
			@Override
			public Iterator iterator() {
				return new Iterator<Integer>() {
					int current = from;
					public boolean hasNext() { return current < to; }
					public Integer next() {
						if (!hasNext()) { throw new NoSuchElementException(); }
						return current++;
					}
					public void remove() { /*Optional; not implemented.*/ }
				};
			}
		};
		assertTrue(CollectionUtils.sizeIsEmpty(i));
	}

	@Test
	void sizeIsEmptyMap1() {
		HashMap<Integer, Integer> hash = new HashMap<>();
		hash.put(4, 6);
		assertFalse(CollectionUtils.sizeIsEmpty(hash));
	}

	@Test
	void sizeIsEmptyMap2() {
		HashMap<Integer, Integer> hash = new HashMap<>();
		assertTrue(CollectionUtils.sizeIsEmpty(hash));
	}

	@Test
	void sizeIsEmptyArray1() {
		Integer[] array = {};
		assertTrue(CollectionUtils.sizeIsEmpty(array));
	}
	@Test
	void sizeIsEmptyArray2() {
		Integer[] array = {5};
		assertFalse(CollectionUtils.sizeIsEmpty(array));
	}


	@Test
	void sizeIsEmptyIterator1() {
		Iterator it = new Iterator() {
			@Override
			public boolean hasNext() {
				return true;
			}

			@Override
			public Object next() {
				return null;
			}
		};
		assertFalse(CollectionUtils.sizeIsEmpty(it));
	}

	@Test
	void sizeIsEmptyIterator2() {
		Iterator it = new Iterator() {
			@Override
			public boolean hasNext() {
				return false;
			}

			@Override
			public Object next() {
				return null;
			}
		};
		assertTrue(CollectionUtils.sizeIsEmpty(it));
	}

	@Test
	void sizeIsEmptyEnumeration1() {
		Enumeration en = new Enumeration() {
			@Override
			public boolean hasMoreElements() {
				return false;
			}

			@Override
			public Object nextElement() {
				return null;
			}
		};

		assertTrue(CollectionUtils.sizeIsEmpty(en));
	}

	@Test
	void sizeIsEmptyEnumeration2() {
		Enumeration en = new Enumeration() {
			@Override
			public boolean hasMoreElements() {
				return true;
			}

			@Override
			public Object nextElement() {
				return null;
			}
		};

		assertFalse(CollectionUtils.sizeIsEmpty(en));
	}

	@Test
	void isEmpty1() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(1);

		assertFalse(CollectionUtils.isEmpty(list));
	}

	@Test
	void isEmpty2() {
		ArrayList<Integer> list = new ArrayList<>();

		assertTrue(CollectionUtils.isEmpty(list));
	}

	@Test
	void isNotEmpty1() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(1);

		assertTrue(CollectionUtils.isNotEmpty(list));
	}

	@Test
	void isNotEmpty2() {
		ArrayList<Integer> list = new ArrayList<>();

		assertFalse(CollectionUtils.isNotEmpty(list));
	}

	@Test
	void reverseArray() {
		Integer[] array = {-4, 6, 0, -2, 12};
		Integer[] expected = {12, -2, 0, 6, -4};
		CollectionUtils.reverseArray(array);
		assertArrayEquals(expected, array);
	}

	@Test
	void isFull1() {
		BoundedCollection c = new BoundedCollection() {
			@Override
			public boolean isFull() {
				return size() >= maxSize();
			}

			@Override
			public int maxSize() {
				return 5;
			}

			@Override
			public int size() {
				return 2;
			}

			@Override
			public boolean isEmpty() {
				return false;
			}

			@Override
			public boolean contains(Object o) {
				return false;
			}

			@Override
			public Iterator iterator() {
				return null;
			}

			@Override
			public Object[] toArray() {
				return new Object[0];
			}

			@Override
			public Object[] toArray(Object[] a) {
				return new Object[0];
			}

			@Override
			public boolean add(Object o) {
				return false;
			}

			@Override
			public boolean remove(Object o) {
				return false;
			}

			@Override
			public boolean containsAll(Collection c) {
				return false;
			}

			@Override
			public boolean addAll(Collection c) {
				return false;
			}

			@Override
			public boolean removeAll(Collection c) {
				return false;
			}

			@Override
			public boolean retainAll(Collection c) {
				return false;
			}

			@Override
			public void clear() {

			}
		};
		assertFalse(CollectionUtils.isFull(c));
	}

	@Test
	void isFull2() {
		BoundedCollection c = new BoundedCollection() {
			@Override
			public boolean isFull() {
				return size() >= maxSize();
			}

			@Override
			public int maxSize() {
				return 5;
			}

			@Override
			public int size() {
				return 5;
			}

			@Override
			public boolean isEmpty() {
				return false;
			}

			@Override
			public boolean contains(Object o) {
				return false;
			}

			@Override
			public Iterator iterator() {
				return null;
			}

			@Override
			public Object[] toArray() {
				return new Object[0];
			}

			@Override
			public Object[] toArray(Object[] a) {
				return new Object[0];
			}

			@Override
			public boolean add(Object o) {
				return false;
			}

			@Override
			public boolean remove(Object o) {
				return false;
			}

			@Override
			public boolean containsAll(Collection c) {
				return false;
			}

			@Override
			public boolean addAll(Collection c) {
				return false;
			}

			@Override
			public boolean removeAll(Collection c) {
				return false;
			}

			@Override
			public boolean retainAll(Collection c) {
				return false;
			}

			@Override
			public void clear() {

			}
		};
		assertTrue(CollectionUtils.isFull(c));
	}

	@Test
	void isFull3() {
		ArrayList<Integer> list = new ArrayList<>();
		assertFalse(CollectionUtils.isFull(list));
	}

	@Test
	void maxSize1() {
		BoundedCollection c = new BoundedCollection() {
			@Override
			public boolean isFull() {
				return false;
			}

			@Override
			public int maxSize() {
				return 5;
			}

			@Override
			public int size() {
				return 0;
			}

			@Override
			public boolean isEmpty() {
				return false;
			}

			@Override
			public boolean contains(Object o) {
				return false;
			}

			@Override
			public Iterator iterator() {
				return null;
			}

			@Override
			public Object[] toArray() {
				return new Object[0];
			}

			@Override
			public Object[] toArray(Object[] a) {
				return new Object[0];
			}

			@Override
			public boolean add(Object o) {
				return false;
			}

			@Override
			public boolean remove(Object o) {
				return false;
			}

			@Override
			public boolean containsAll(Collection c) {
				return false;
			}

			@Override
			public boolean addAll(Collection c) {
				return false;
			}

			@Override
			public boolean removeAll(Collection c) {
				return false;
			}

			@Override
			public boolean retainAll(Collection c) {
				return false;
			}

			@Override
			public void clear() {

			}
		};
		assertEquals(5, CollectionUtils.maxSize(c));
	}

	@Test
	void maxSize2() {
		ArrayList<Integer> list = new ArrayList<Integer>();
		var result = CollectionUtils.maxSize(list);
		assertEquals(-1, result);
	}

	@Test
	void collate1() {
		ArrayList<Integer> listA = new ArrayList<>(Arrays.asList(-7, 0, 1, 4, 5, 7));
		ArrayList<Integer> listB = new ArrayList<>(Arrays.asList(-325, -2, 1, 54, 241));


		ArrayList<Integer> expected = new ArrayList<>(Arrays.asList(-325, -7, -2, 0, 1, 1, 4, 5, 7, 54, 241));

		var result = CollectionUtils.collate(listA, listB);

		assertIterableEquals(expected, result);
	}

	@Test
	void collate2() {
		ArrayList<Integer> listA = new ArrayList<>(Arrays.asList(-7, 0, 1, 4, 5, 7));
		ArrayList<Integer> listB = new ArrayList<>(Arrays.asList(-325, -2, 1, 54, 241));


		ArrayList<Integer> expected = new ArrayList<>(Arrays.asList(-325, -7, -2, 0, 1, 4, 5, 7, 54, 241));

		var result = CollectionUtils.collate(listA, listB, false);

		assertIterableEquals(expected, result);
	}

	@Test
	void collate3() {
		ArrayList<Integer> listA = new ArrayList<>(Arrays.asList(-7, 0, 1, 4, 5, 7));
		ArrayList<Integer> listB = new ArrayList<>(Arrays.asList(-325, -2, 1, 54, 241));


		ArrayList<Integer> expected = new ArrayList<>(Arrays.asList(-325, -7, -2, 0, 1, 1, 4, 5, 7, 54, 241));

		Comparator cmp = (o1, o2) -> {
			Integer x = (Integer) o1;
			Integer y = (Integer) o2;
			return (x < y) ? -1 : ((x == y) ? 0 : 1);
		};

		var result = CollectionUtils.collate(listA, listB, cmp);

		assertIterableEquals(expected, result);
	}

	@Test
	void permutations() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(5);
		list.add(7);

		ArrayList<ArrayList<Integer>> expected = new ArrayList<>();
		expected.add(new ArrayList<>(Arrays.asList(5, 7)));
		expected.add(new ArrayList<>(Arrays.asList(7, 5)));

		var result = CollectionUtils.permutations(list);

		assertIterableEquals(expected, result);
	}

	@Test
	void retainAll1() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(-5);
		list.add(0);
		list.add(4);
		list.add(15);
		list.add(23);
		list.add(-125);
		list.add(8);

		ArrayList<Integer> retain = new ArrayList<>();
		retain.add(0);
		retain.add(15);
		retain.add(-125);
		retain.add(1);

		ArrayList<Integer> expected = new ArrayList<>();
		expected.add(0);
		expected.add(15);
		expected.add(-125);

		var result = CollectionUtils.retainAll(list, retain);

		assertIterableEquals(expected, result);
	}

	@Test
	void retainAll2() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(-5);
		list.add(0);
		list.add(4);
		list.add(15);
		list.add(23);
		list.add(-125);
		list.add(8);

		ArrayList<Integer> retain = new ArrayList<>();
		retain.add(0);
		retain.add(15);
		retain.add(-125);
		retain.add(1);

		Equator eq = new Equator() {
			@Override
			public boolean equate(Object o1, Object o2) {
				Integer i1, i2;
				i1 = (Integer) o1;
				i2 = (Integer) o2;
				return i1 == i2;
			}

			@Override
			public int hash(Object o) {
				return 0;
			}
		};

		ArrayList<Integer> expected = new ArrayList<>();
		expected.add(0);
		expected.add(15);
		expected.add(-125);

		var result = CollectionUtils.retainAll(list, retain, eq);

		assertIterableEquals(expected, result);
	}

	@Test
	void removeAll1() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(-5);
		list.add(0);
		list.add(4);
		list.add(15);
		list.add(23);
		list.add(-125);
		list.add(8);

		ArrayList<Integer> remove = new ArrayList<>();
		remove.add(0);
		remove.add(15);
		remove.add(-125);
		remove.add(1);

		ArrayList<Integer> expected = new ArrayList<>();
		expected.add(-5);
		expected.add(4);
		expected.add(23);
		expected.add(8);

		var result = CollectionUtils.removeAll(list, remove);

		assertIterableEquals(expected, result);
	}

	@Test
	void removeAll2() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(-5);
		list.add(0);
		list.add(4);
		list.add(15);
		list.add(23);
		list.add(-125);
		list.add(8);

		ArrayList<Integer> remove = new ArrayList<>();
		remove.add(0);
		remove.add(15);
		remove.add(-125);
		remove.add(1);

		Equator eq = new Equator() {
			@Override
			public boolean equate(Object o1, Object o2) {
				Integer i1, i2;
				i1 = (Integer) o1;
				i2 = (Integer) o2;
				return i1 == i2;
			}

			@Override
			public int hash(Object o) {
				return 0;
			}
		};

		ArrayList<Integer> expected = new ArrayList<>();
		expected.add(-5);
		expected.add(4);
		expected.add(23);
		expected.add(8);

		var result = CollectionUtils.removeAll(list, remove, eq);

		assertIterableEquals(expected, result);
	}

	@Test
	void synchronizedCollection() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(5);

		var result = CollectionUtils.synchronizedCollection(list);

		assertIterableEquals(list, result);
	}

	@Test
	void unmodifiableCollection1() {
		ArrayList<Integer> list = new ArrayList<>();
		var result = CollectionUtils.unmodifiableCollection(list);
		assertThrows(UnsupportedOperationException.class, () -> {result.add(5);});
	}

	@Test
	void unmodifiableCollection2() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(5);

		var result = CollectionUtils.unmodifiableCollection(list);
		assertIterableEquals(list, result);
	}

	@Test
	void predicatedCollection1() {
		ArrayList<Integer> list = new ArrayList<>();

		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};

		var result = CollectionUtils.predicatedCollection(list, predicate);

		assertThrows(IllegalArgumentException.class, () -> {result.add(5);});
	}

	@Test
	void predicatedCollection2() {
		ArrayList<Integer> expected = new ArrayList<>();
		expected.add(12);
		expected.add(50);
		expected.add(173);


		ArrayList<Integer> list = new ArrayList<>();

		Predicate predicate = object -> {
			Integer n = (Integer) object;
			return n > 10;
		};


		var result = CollectionUtils.predicatedCollection(list, predicate);
		result.add(12);
		result.add(50);
		result.add(173);

		assertIterableEquals(expected, result);

	}

	@Test
  	void transformingCollection() {
		ArrayList<Integer> expected = new ArrayList<>();
		expected.add(7);
		expected.add(7);
		expected.add(7);

		ArrayList<Integer> list = new ArrayList<>();
		var result = CollectionUtils.transformingCollection(list, TransformerUtils.constantTransformer(7));
		result.add(181);
		result.add(-23);
		result.add(0);

		assertIterableEquals(expected, result);

	}

	@Test
  	void extractSingleton() {
		ArrayList<Integer> list = new ArrayList<>();
		list.add(5);
		var result = CollectionUtils.extractSingleton(list);

		assertEquals(5, result);
	}
} 